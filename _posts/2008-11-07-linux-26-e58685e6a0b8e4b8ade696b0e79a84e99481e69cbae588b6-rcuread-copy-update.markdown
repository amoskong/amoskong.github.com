---
author: amosk
comments: true
date: 2008-11-07 09:56:36+00:00
layout: post
slug: linux-26-%e5%86%85%e6%a0%b8%e4%b8%ad%e6%96%b0%e7%9a%84%e9%94%81%e6%9c%ba%e5%88%b6-rcuread-copy-update
title: Linux 2.6 内核中新的锁机制 RCU(Read-Copy Update)
wordpress_id: 290
categories:
- Linux
---

> 本文详细地介绍了 Linux 2.6 内核中新的锁机制 RCU(Read-Copy Update) 的实现机制，使用要求与典型应用。


一、 引言

众所周知，为了保护共享数据,需要一些同步机制,如自旋锁(spinlock)，读写锁(rwlock)，它们使用起来非常简单,而且是一种很有效 的同步机制，在UNIX系统和Linux系统中得到了广泛的使用。但是随着计算机硬件的快速发展，获得这种锁的开销相对于CPU的速度在成倍地增加，原因 很简单，CPU的速度与访问内存的速度差距越来越大，而这种锁使用了原子操作指令，它需要原子地访问内存，也就说获得锁的开销与访存速度相关，另外在大部 分非x86架构上获取锁使用了内存栅(Memory Barrier)，这会导致处理器流水线停滞或刷新，因此它的开销相对于CPU速度而言就越来越大。表1数据证明了这一点。
![表1 在700MHz奔腾III机器上一些操作的开销](http://www.ibm.com/developerworks/cn/linux/l-rcu/images/table0.gif)

表1是在700MHz的奔腾III机器上的基本操作的开销，在该机器上一个时钟周期能够执行两条整数指令。在1.8GHz的奔腾4机器上, 原子加1指令的开销要比700MHz的奔腾III机器慢75纳秒(ns)，尽管CPU速度快两倍多。

这种锁机制的另一个问题在于其可扩展性，在多处理器系统上，可扩展性非常重要，否则根本无法发挥其性能。图1表明了Linux上各种锁的扩展性。
**图 1 Linux的4种锁机制的扩展性**
![图 1  Linux的4种锁机制的扩展性](http://www.ibm.com/developerworks/cn/linux/l-rcu/images/image002.jpg)

注：refcnt表示自旋锁与引用记数一起使用。

读写锁rwlock在两个CPU的情况下性能反倒比一个CPU的差，在四个CPU的情况下，refcnt的性能要高于rwlock，refcnt大 约是理论性能的45%，而rwlock是理论性能的39%,自旋缩spinlock的性能明显好于refcnt和rwlock，但它也只达到了理性性能的 57%，brlock（Big Reader Lock）性能可以线性扩展。Brlock是由Redhat的Ingo Molnar实现的一个高性能的rwlock，它适用于读特多而写特少的情况，读者获得brlock的开销很低，但写者获得锁的开销非常大，而且它只预定 义了几个锁，用户无法随便定义并使用这种锁，它也需要为每个CPU定义一个锁状态数组，因此这种锁并没有被作为rwlock的替代方案广泛使用，只是在一 些特别的地方使用到。

正是在这种背景下，一个高性能的锁机制RCU呼之欲出，它克服了以上锁的缺点，具有很好的扩展性，但是这种锁机制的使用范围比较窄，它只适用于读多写少的情况，如网络路由表的查询更新、设备状态表的维护、数据结构的延迟释放以及多径I/O设备的维护等。

RCU并不是新的锁机制，它只是对Linux内核而言是新的。早在二十世纪八十年代就有了这种机制，而且在生产系

统中使用了这种机制，但这种早期的实现并不太好，在二十世纪九十年代出现了一个比较高效的实现，而在linux中是在开发内核2.5.43中引入该技术的并正式包含在2.6内核中。








![](http://www.ibm.com/i/v14/rules/blue_rule.gif)
![](http://www.ibm.com/i/c.gif)





























二、RCU的原理

RCU(Read-Copy Update)，顾名思义就是读-拷贝修改，它是基于其原理命名的。对于被RCU保护的共享数据结构，读者不需要获得任何锁就可以访问它，但写者在访问它 时首先拷贝一个副本，然后对副本进行修改，最后使用一个回调（callback）机制在适当的时机把指向原来数据的指针重新指向新的被修改的数据。这个时 机就是所有引用该数据的CPU都退出对共享数据的操作。

因此RCU实际上是一种改进的rwlock，读者几乎没有什么同步开销，它不需要锁，不使用原子指令，而且在除alpha的所有架构上也不需要内存 栅（Memory Barrier），因此不会导致锁竞争，内存延迟以及流水线停滞。不需要锁也使得使用更容易，因为死锁问题就不需要考虑了。写者的同步开销比较大，它需要 延迟数据结构的释放，复制被修改的数据结构，它也必须使用某种锁机制同步并行的其它写者的修改操作。读者必须提供一个信号给写者以便写者能够确定数据可以 被安全地释放或修改的时机。有一个专门的垃圾收集器来探测读者的信号，一旦所有的读者都已经发送信号告知它们都不在使用被RCU保护的数据结构，垃圾收集 器就调用回调函数完成最后的数据释放或修改操作。 RCU与rwlock的不同之处是：它既允许多个读者同时访问被保护的数据，又允许多个读者和多个写者同时访问被保护的数据（注意：是否可以有多个写者并 行访问取决于写者之间使用的同步机制），读者没有任何同步开销，而写者的同步开销则取决于使用的写者间同步机制。但RCU不能替代rwlock，因为如果 写比较多时，对读者的性能提高不能弥补写者导致的损失。

读者在访问被RCU保护的共享数据期间不能被阻塞，这是RCU机制得以实现的一个基本前提，也就说当读者在引用被RCU保护的共享数据期间，读者所 在的CPU不能发生上下文切换，spinlock和rwlock都需要这样的前提。写者在访问被RCU保护的共享数据时不需要和读者竞争任何锁，只有在有 多于一个写者的情况下需要获得某种锁以与其他写者同步。写者修改数据前首先拷贝一个被修改元素的副本，然后在副本上进行修改，修改完毕后它向垃圾回收器注 册一个回调函数以便在适当的时机执行真正的修改操作。等待适当时机的这一时期称为grace period，而CPU发生了上下文切换称为经历一个quiescent state，grace period就是所有CPU都经历一次quiescent state所需要的等待的时间。垃圾收集器就是在grace period之后调用写者注册的回调函数来完成真正的数据修改或数据释放操作的。

以下以链表元素删除为例详细说明这一过程。

写者要从链表中删除元素 B，它首先遍历该链表得到指向元素 B 的指针，然后修改元素 B 的前一个元素的 next 指针指向元素 B 的 next 指针指向的元素C，修改元素 B 的 next 指针指向的元素 C 的 prep 指针指向元素 B 的 prep指针指向的元素 A,在这期间可能有读者访问该链表，修改指针指向的操作是原子的，所以不需要同步，而元素 B 的指针并没有去修改，因为读者可能正在使用 B 元素来得到下一个或前一个元素。写者完成这些操作后注册一个回调函数以便在 grace period 之后删除元素 B，然后就认为已经完成删除操作。垃圾收集器在检测到所有的CPU不在引用该链表后，即所有的 CPU 已经经历了 quiescent state,grace period 已经过去后，就调用刚才写者注册的回调函数删除了元素 B。
**图 2 使用 RCU 进行链表删除操作**
![图 2  使用 RCU 进行链表删除操作](http://www.ibm.com/developerworks/cn/linux/l-rcu/images/image004.jpg)








![](http://www.ibm.com/i/v14/rules/blue_rule.gif)
![](http://www.ibm.com/i/c.gif)











![](http://www.ibm.com/i/c.gif)

















三、RCU 实现机制<!-- more -->

按照第二节所讲原理，对于读者，RCU 仅需要抢占失效，因此获得读锁和释放读锁分别定义为：

    
    #define rcu_read_lock()          preempt_disable()
    #define rcu_read_unlock()        preempt_enable()


它们有一个变种：

    
    #define rcu_read_lock_bh()       local_bh_disable()
    #define rcu_read_unlock_bh()     local_bh_enable()


这个变种只在修改是通过 call_rcu_bh 进行的情况下使用，因为 call_rcu_bh将把 softirq 的执行完毕也认为是一个 quiescent state，因此如果修改是通过 call_rcu_bh 进行的，在进程上下文的读端临界区必须使用这一变种。

每一个 CPU 维护两个数据结构rcu_data,rcu_bh_data，它们用于保存回调函数，函数call_rcu和函数call_rcu_bh用户注册回调函 数，前者把回调函数注册到rcu_data，而后者则把回调函数注册到rcu_bh_data，在每一个数据结构上，回调函数被组成一个链表，先注册的排 在前头，后注册的排在末尾。

当在CPU上发生进程切换时，函数rcu_qsctr_inc将被调用以标记该CPU已经经历了一个quiescent state。该函数也会被时钟中断触发调用。

时钟中断触发垃圾收集器运行，它会检查：



	
  1. 否在该CPU上有需要处理的回调函数并且已经经过一个grace period；

	
  2. 否没有需要处理的回调函数但有注册的回调函数；

	
  3. 否该CPU已经完成回调函数的处理；

	
  4. 否该CPU正在等待一个quiescent state的到来；


如果以上四个条件只要有一个满足，它就调用函数rcu_check_callbacks。

函数rcu_check_callbacks首先检查该CPU是否经历了一个quiescent state，如果：

1． 当前进程运行在用户态；
或

2． 当前进程为idle且当前不处在运行softirq状态，也不处在运行IRQ处理函数的状态；

那 么，该CPU已经经历了一个quiescent state，因此通过调用函数rcu_qsctr_inc标记该CPU的数据结构rcu_data和rcu_bh_data的标记字段 passed_quiesc，以记录该CPU已经经历一个quiescent state。

否则，如果当前不处在运行softirq状态，那么，只标记该CPU的数据结构rcu_bh_data的标记字段passed_quiesc，以记录该CPU已经经历一个quiescent state。注意，该标记只对rcu_bh_data有效。

然后，函数rcu_check_callbacks将调用tasklet_schedule，它将调度为该CPU设置的tasklet rcu_tasklet，每一个CPU都有一个对应的rcu_tasklet。

在时钟中断返回后，rcu_tasklet将在softirq上下文被运行。

rcu_tasklet将运行函数rcu_process_callbacks，函数rcu_process_callbacks可能做以下事情：

1． 开始一个新的grace period；这通过调用函数rcu_start_batch实现。

2． 运行需要处理的回调函数；这通过调用函数rcu_do_batch实现。

3． 检查该CPU是否经历一个quiescent state；这通过函数rcu_check_quiescent_state实现

如 果还没有开始grace period，就调用rcu_start_batch开始新的grace period。调用函数rcu_check_quiescent_state检查该CPU是否经历了一个quiescent state,如果是并且是最后一个经历quiescent state的CPU，那么就结束grace period，并开始新的grace period。如果有完成的grace period，那么就调用rcu_do_batch运行所有需要处理的回调函数。函数rcu_process_callbacks将对该CPU的两个数据 结构rcu_data和rcu_bh_data执行上述操作。








![](http://www.ibm.com/i/v14/rules/blue_rule.gif)
![](http://www.ibm.com/i/c.gif)











![](http://www.ibm.com/i/c.gif)















四、RCU API

rcu_read_lock()

读者在读取由RCU保护的共享数据时使用该函数标记它进入读端临界区。

rcu_read_unlock()

该函数与rcu_read_lock配对使用，用以标记读者退出读端临界区。夹在这两个函数之间的代码区称为"读端临界区"(read-side critical section)。读端临界区可以嵌套，如图3，临界区2被嵌套在临界区1内。
**图 3 嵌套读端临界区示例**
![图 3  嵌套读端临界区示例](http://www.ibm.com/developerworks/cn/linux/l-rcu/images/image006.gif)

synchronize_rcu()

该函数由RCU写端调用，它将阻塞写者，直到经过grace period后，即所有的读者已经完成读端临界区，写者才可以继续下一步操作。如果有多个RCU写端调用该函数，他们将在一个grace period之后全部被唤醒。注意，该函数在2.6.11及以前的2.6内核版本中为synchronize_kernel，只是在2.6.12才更名为 synchronize_rcu,但在2.6.12中也提供了synchronize_kernel和一个新的函数synchronize_sched， 因为以前有很多内核开发者使用synchronize_kernel用于等待所有CPU都退出不可抢占区，而在RCU设计时该函数只是用于等待所有CPU 都退出读端临界区，它可能会随着RCU实现的修改而发生语意变化，因此为了预先防止这种情况发生，在新的修改中增加了专门的用于其它内核用户的 synchronize_sched函数和只用于RCU使用的synchronize_rcu，现在建议非RCU内核代码部分不使用 synchronize_kernel而使用synchronize_sched，RCU代码部分则使用 synchronize_rcu，synchronize_kernel之所以存在是为了保证代码兼容性。

synchronize_kernel()

其他非RCU的内核代码使用该函数来等待所有CPU处在可抢占状态，目前功能等同于synchronize_rcu，但现在已经不建议使用，而使用synchronize_sched。

synchronize_sched()

该函数用于等待所有CPU都处在可抢占状态，它能保证正在运行的中断处理函数处理完毕，但不能保证正在运行的softirq处理完毕。注 意，synchronize_rcu只保证所有CPU都处理完正在运行的读端临界区。注：在2.6.12内核中，synchronize_kernel和 synchronize_sched都实际使用synchronize_rcu，因此当前它们的功能实际是完全等同的，但是将来将可能有大的变化，因此务 必根据需求选择恰当的函数。










    
    void fastcall call_rcu(struct rcu_head *head,
    void (*func)(struct rcu_head *rcu))
    struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
    };






函数 call_rcu 也由 RCU 写端调用，它不会使写者阻塞，因而可以在中断上下文或 softirq 使用，而 synchronize_rcu、synchronize_kernel 和synchronize_shced 只能在进程上下文使用。该函数将把函数 func 挂接到 RCU回调函数链上，然后立即返回。一旦所有的 CPU 都已经完成端临界区操作，该函数将被调用来释放删除的将绝不在被应用的数据。参数 head 用于记录回调函数 func，一般该结构会作为被 RCU 保护的数据结构的一个字段，以便省去单独为该结构分配内存的操作。需要指出的是，函数 synchronize_rcu 的实现实际上使用函数call_rcu。










    
    void fastcall call_rcu_bh(struct rcu_head *head,
    void (*func)(struct rcu_head *rcu))






函数call_ruc_bh功能几乎与call_rcu完全相同，唯一差别就是它把softirq的完成也当作经历一个quiescent state，因此如果写端使用了该函数，在进程上下文的读端必须使用rcu_read_lock_bh。










    
    #define rcu_dereference(p)      ({ \
    typeof(p) _________p1 = p; \
    smp_read_barrier_depends(); \
    (_________p1); \
    })






该宏用于在RCU读端临界区获得一个RCU保护的指针，该指针可以在以后安全地引用，内存栅只在alpha架构上才使用。

除了这些API，RCU还增加了链表操作的RCU版本，因为对于RCU，对共享数据的操作必须保证能够被没有使用同步机制的读者看到，所以内存栅是非常必要的。

static inline void list_add_rcu(struct list_head *new, struct list_head *head) 该函数把链表项new插入到RCU保护的链表head的开头。使用内存栅保证了在引用这个新插入的链表项之前，新链表项的链接指针的修改对所有读者是可见 的。










    
    static inline void list_add_tail_rcu(struct list_head *new,
    struct list_head *head)






该函数类似于list_add_rcu，它将把新的链表项new添加到被RCU保护的链表的末尾。










    
    static inline void list_del_rcu(struct list_head *entry)






该函数从RCU保护的链表中移走指定的链表项entry，并且把entry的prev指针设置为LIST_POISON2，但是并没有把entry的next指针设置为LIST_POISON1，因为该指针可能仍然在被读者用于便利该链表。










    
    static inline void list_replace_rcu(struct list_head *old, struct list_head *new)






该函数是RCU新添加的函数，并不存在非RCU版本。它使用新的链表项new取代旧的链表项old，内存栅保证在引用新的链表项之前，它的链接指针的修正对所有读者可见。










    
    list_for_each_rcu(pos, head)






该宏用于遍历由RCU保护的链表head，只要在读端临界区使用该函数，它就可以安全地和其它_rcu链表操作函数（如list_add_rcu）并发运行。










    
    list_for_each_safe_rcu(pos, n, head)






该宏类似于list_for_each_rcu，但不同之处在于它允许安全地删除当前链表项pos。










    
    list_for_each_entry_rcu(pos, head, member)






该宏类似于list_for_each_rcu，不同之处在于它用于遍历指定类型的数据结构链表，当前链表项pos为一包含struct list_head结构的特定的数据结构。










    
    list_for_each_continue_rcu(pos, head)






该宏用于在退出点之后继续遍历由RCU保护的链表head。










    
    static inline void hlist_del_rcu(struct hlist_node *n)






它从由RCU保护的哈希链表中移走链表项n，并设置n的ppre指针为LIST_POISON2，但并没有设置next为LIST_POISON1,因为该指针可能被读者使用用于遍利链表。










    
    static inline void hlist_add_head_rcu(struct hlist_node *n,
    struct hlist_head *h)






该函数用于把链表项n插入到被RCU保护的哈希链表的开头，但同时允许读者对该哈希链表的遍历。内存栅确保在引用新链表项之前，它的指针修正对所有读者可见。










    
    hlist_for_each_rcu(pos, head)






该宏用于遍历由RCU保护的哈希链表head，只要在读端临界区使用该函数，它就可以安全地和其它_rcu哈希链表操作函数（如hlist_add_rcu）并发运行。










    
    hlist_for_each_entry_rcu(tpos, pos, head, member)






类似于hlist_for_each_rcu，不同之处在于它用于遍历指定类型的数据结构哈希链表，当前链表项pos为一包含struct list_head结构的特定的数据结构。

From: http://hi.baidu.com/jiangguiqing/blog/item/88acc7442f9f2981b3b7dc44.html
