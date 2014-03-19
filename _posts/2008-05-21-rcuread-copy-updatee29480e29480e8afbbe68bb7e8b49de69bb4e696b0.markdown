---
author: amosk
comments: true
date: 2008-05-21 14:53:46+00:00
layout: post
slug: rcuread-copy-update%e2%94%80%e2%94%80%e8%af%bb%e6%8b%b7%e8%b4%9d%e6%9b%b4%e6%96%b0
title: rcu(Read-Copy update)──读拷贝更新
wordpress_id: 237
categories:
- Linux
---

今天在看ULK时，对照源代码，发现在 include/linux/list.c中有好多类似 fun() 、fun_rcu()的函数对
如 list_del()、list_del_rcu()； list_add()、list_add_rcu() 等
这里的rcu是Read-Copy Update的意思，它是2.5/2.6内核中引入的新技术，它通过延迟写操作来提高同步性能。
操作系统中，数据读取操作远多于写操作，而rwlock机制在多处理器环境下随着处理机增多性能会迅速下降。针对这一应用背景，IBM Linux技术中心的Paul E. McKenney 提出了"读拷贝更新"的技术，并将其应用于 Linux 内核中。 RCU 技术的核心是写操作分为“写”和“更新”两步，允许读操作在任何时候无阻访问，当系统有写操作时，更新动作一直延迟到对该数据的所有读操作完成为止。Linux 链表中的RCU功能只是 Linux RCU 的很小一部分，对RCU链表的使用和一般链表的使用方法基本相同。

在删除表项的函数中，用到了include/linux/poison.h 中定义的两个宏
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

static inline void hlist_del(struct hlist_node *n)
{
__hlist_del(n);
n->next = LIST_POISON1;
n->pprev = LIST_POISON2;
}

static inline void INIT_LIST_HEAD(struct list_head *list)
{
list->next = list;
list->prev = list;
}

这是为了防止意外使用一个已被删除的表项指针产生页错异常，在初始化时则是将表头的pret和next指针置都执行头结点。
