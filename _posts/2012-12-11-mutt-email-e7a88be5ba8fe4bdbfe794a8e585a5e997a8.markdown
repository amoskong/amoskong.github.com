---
author: amosk
comments: true
date: 2012-12-11 14:05:01+00:00
layout: post
slug: mutt-email-%e7%a8%8b%e5%ba%8f%e4%bd%bf%e7%94%a8%e5%85%a5%e9%97%a8
title: Mutt email 程序使用入门
wordpress_id: 896
categories:
- Linux
---


### (用了thunderbird一年，好多mutt特性都忘了，mutt还是利器呀！)

### From: [http://blog.163.com/peigen_peigen/blog/static/27047802007311102914457/](http://blog.163.com/peigen_peigen/blog/static/27047802007311102914457/)


"All mail clients suck. This one just sucks less." -me, circa 1995

你也许听说过这句话？这不是危言耸听，我还没有遇到一个令我满意的 email 程序，直到我遇到 mutt。它不是图形界面的，但是它非常强大和方便。我曾经把它忽略，但是后来我发现其它 email 程序都有某种我不喜欢的怪毛病。最后我选择了 Mutt。

有人说 Gnus 才是最好的 email 客户端，可是 Gnus 要达到 Mutt 这种效果和方便程度，你需要付出太多代价。所以我宁愿使用 Mutt 调用 Emacs 来编辑 email 而不愿把 Gnus 配置来处理 email.


### Mutt 的特点   <!-- more -->


mutt 具有以下特点：


	
  \* _超强的信件分类功能_你可以设置几乎任意的条件来从一堆信件里找到你所需要的那封。比如，你可以说：“只显示一个月之类，不是清华大学发来的，内容包含‘光盘’两个字的信件”，“把从 fvwm 邮件列表一个星期以前发来的，而且还没有看过的信件全部移到叫 old-fvwm 的信箱”……

	
  \* _信件打分排序功能_你可以给你的信件打分，比如我说：

	
    \* 主题包含 "Circulation Notices" 的 +3 分。否则小心被图书馆罚款 :P

	
    \* 从我爸爸发来的信件 +2 分。听爸爸话……

	
    \* 主题包含"通知"两个字 +2 分。随时听取党中央号召 :)

	
    \* 主题包含"believe me", "believe.\*dream", "win.\*free" 字样的, -1 分。这些一般都是广告。

	
    \* 新的信件 +4 分。新的应该最先看。

	
    \* 新的而上次忘了读的信件(old), +1 分。可能太忙了上次忘了看的信，这次应该先看。


信件最后的得分就是它的这些分数相加的结果。这样处理之后，你最想看的信件肯定就在最上面了。

	
  \* _几乎任意条件的彩色设置_你看我的 Mutt 可以变成这个样子。当然这太花了，我不会设置这么多颜色的 :)![mutt-color](http://www.kreny.com/images/mutt-color.png)

	
  \* _可以随意绑定热键_这 个功能类似 Emacs。你可以把几乎任意的功能绑定到键盘。你可以让 Mutt 的行为变成你喜欢的编辑器。比如我习惯了 VIM 的控制方式，我就把 "gg" 绑定到 "first-entry", 把 "G" 绑定到 "last-entry", 把 "Ctrl-F" 绑定到 next-page, 把 "Ctrl-B" 绑定到 previous-page.

	
  \* _设置条件挂钩_你 可以对满足不同条件的信件，信箱采取不同的设置。比如，对于用来收邮件的那些信箱，显示邮件时只显示 from, date, subject, x-mailer 这几个邮件头，而对 sent-mail 信箱还显示 to 这个邮件头；发给我家人，朋友的信件都存到一个特别的信箱中保存。

	
  \* _批量邮件处理_你可以把一些邮件作上标记(tag)，然后对它们进行同意操作，比如删除，存到其它文件，删除附件，……

	
  \* _任选编辑器_用 一个强大的编辑器来编辑你的 email 你才能高效的完成编辑。一般 email 客户端都是用的自己内嵌的编辑器，这些编辑器一般功能很弱。mutt 并没有试图自己写一个编辑器，因为它明显不可能超过 VIM 和 Emacs, 所以 mutt 可以让你自己选择你喜欢的编辑器，它会去调用它，并且设置很多方便编辑 email 的参数。编辑器编辑完毕后 mutt 会从编辑器得到编辑好的文本，然后你可以加附件什么的。我现在在 mutt 里使用 Emacs 编辑器。

	
  \* _高级的 MIME 支持_Mutt 不像一般的 email 程序那样直接支持打开某些种类的附件。因为附件的种类实在太多，一个 email 客户端没有可能自己实现所有的功能。所以 Mutt 提供了 .mailcap 的设置。你可以启用你最喜欢的程序来打开某种特定类型的附件。比如，我可以让 lynx 帮我把含有 HTML 附件的信件都转成文本在 Mutt 里显示，我让 ImageMagick 的 display 程序帮我显示图片……

	
  \* _支持PGP加密_Mutt 可以利用 GnuPG 这样的程序来对信件进行 PGP 加密和数字签名。别人可以用你的公用密钥给你发一封只有你才能看到的信件。你也可以用你的私有密钥给信件“签名”，收到信的人可以用你公布的公钥验证这封信确实是你发出来的。

	
  \* _Mutt是免费的_听了上面那么多好处之后，还有比这更好的消息吗？




### Mutt 到哪里去找？


Mutt 的主页在 [http://www.mutt.org/](http://www.mutt.org/)。上面有所有源程序和说明文档。


### Mutt 跟其它 email 程序有什么重大区别吗？


Mutt 显然是一个 Unix 的邮件程序，它跟一般的 Windows 邮件程序不同，它不是一个包罗万象的大杂烩。你甚至会发现它根本不直接发出邮件，它从来不自己编辑邮件，它从来不自己对邮件进行加密和数字签名……

Mutt 更像一个文件管理器，只不过它管理的是email。它的功能是借助各个最强大的程序来实现的。这符合 UNIX 的设计思想。



	
  \* 当 Mutt 需要编辑邮件时，它有可能调用 Emacs, vi, VIM, pico, ……等编辑器。

	
  \* 当 Mutt 需要发信时，它把需要发出的信件放到 sendmail 的队列里，就什么都不管了。

	
  \* 当需要数字签名时，Mutt 会把信件交给 GnuPG 之类的程序处理一下，然后再发出去。

	
  \* 怎么收邮件呢？Mutt 不会自己到 POP 服务器去取邮件，你需要一个 fetchmail 程序，帮你把 email 从 POP 服务器取回来，转发到自己的 sendmail 的邮箱里。这样看起来就是你的主机成为了一个完整的 UNIX 网络工作站。


是不是觉得挺麻烦？其实有些 patch 可以使 Mutt 不依赖于这些程序，而自己处理收发工作。但是，强烈建议你使用这些外部程序！到时候你就知道这些东西的好处了。首先，VIM, sendmail, fetchmail 这些程序都是经过千锤百炼的质量信得过的程序，用它们编辑，发送，收取邮件你绝对放心。其次，你得到了一个 UNIX 网络工作站的功能：

	
  \* sendmail 不但可以帮 Mutt 发出邮件，也可以帮其它 Unix 程序比如 tin 发送邮件。如果你需要一个邮件服务器帮你中转，那么你只需要设置一次就可以使所有的用户的所有这样的程序都自动可以发送邮件，不用每个程序都去设置帐号了。

	
  \* fetchmail 收到邮件之后会转发给本地的 sendmail. sendmail 如果允许 .forward, 你就可以在自己的目录里编辑一个 .forward 文件，信件可以自动被转发到其它地方或者经过一个过滤器过滤。你可以自己用perl等语言来写一个过滤器，它可以根据信件内容实现很多功能，比如自动回复 等等。比如我就写了一个简单的过滤器，它可以记录所有发件人的地址，如果我把 [helloooo](http://www.kreny.com/docs/programs.html#bbsbot) 机器人连接到过滤器，恐怕你们就会收到可爱的 helloooo 的回信了 :)




### Mutt 使用指南


Mutt 的用法类似 VIM。你的每一个键都是一个命令，你可以在配置文件~/.muttrc设置很多选项来改变 Mutt 的行为。我没有太多时间写一个入门的介绍。你可以自己看看 [Mutt Manual](http://www.kreny.com/docs/mutt-manual/index.html)。我下面只解决一些中国人用 Mutt 常常遇到的问题。


### 基本配置


你一开始看到 Mutt 说明书上说的配置方法可能不知所措。现在我把你开始用的时候需要的一些必要的配置说一下。



	
  1. alternates这个变量应该设置为一个正则表达式，它是你有可能收到信件的地址。比如我的很简单，只有一个地址：

    
    set alternates="wang-y01@mails.tsinghua.edu.cn"


这个变量有助于 Mutt 显示邮件的地址特征。一般 Mutt 会在index中显示几种不同的邮件地址特征，它们是由 $to_chars 变量指定的。

	
  2. to_chars一般 $to_chars 的定义为 " +TCFL".

	
    \* " "(空): 表示这封邮件不是给你的，也就是说 To: 和 Cc: Bcc: 都没有你的地址，很多转发的邮件，未确认的邮件列表邮件，垃圾邮件都有这个特征。

	
    \* +: 表示你是收件人(To: 是你的地址之一)，而且是唯一的收件人。

	
    \* T: 表示你是收件人(To: 包括了你的地址之一)，但是你不是唯一的收件人。这是一封群体信件。

	
    \* C: 表示你的地址出现在 CC:，但是你不是唯一的被抄送的人。

	
    \* F: 表示这封邮件是你发出去的。

	
    \* L: 表示这是一封你已经加入的邮件列表寄来的。


你看看下面这幅图，就是mutt 有可能出现的一种列表，你看到地址特征没有？实际上地址特征出现在列表中的位置是可以改变的。待会儿在 $index_format 里你会看到的。

![mutt-to](http://www.kreny.com/images/mutt-to.png)

	
  3. index_format这是一个格式字符串，用来控制你的index的列表显示。它的缺省定义是：

    
    set index_format="%4C %Z %{\%b %d} %-15.15L (%4l) %s"


显示出来就是这个样子：
![index-original](http://www.kreny.com/images/index-original.png)

这 里有一个简单的对应关系，%4C表示4位数的序号，%Z是邮件状态，你看到那个 "r" 了吗？也就是说我已经回了这封信。%Z 还包含那个 "T", 也就是说这封信不只是寄给我一个人的，我爸爸每次寄信都会CC他自己一份 :)

     %\{\%b \%d} 是日期格式，它是由 strftime() 函数的格式定义的。这里 %b 就是根据当前的 locale 设置的月份简称，“12月”。%d 就是十进制表示的每月的日号，“31”。后面的……你自己看看manual吧，我不罗嗦了。

	
  4. mailboxes指定你有那些信箱文件。当你按 "c" 切换信箱时，再按 Tab 键，这些信箱就可供你选择。

    
    mailboxes Mailbox sent-mail




	
  5. header这是一个 bool 型变量。它表明你在回信时引用原文是否加入原文的邮件头。

    
    set header=no




	
  6. quit![mutt-quit](http://www.kreny.com/images/mutt-quit.png)可以设置为 yes, no, ask-yes, 或者 ask-no. 这是说，当你按q退出时，是否提示你(ask-yes,ask-no)，还是直接就退出了(yes)，还是根本不理你(no)。

    
    set quit=ask-yes




	
  7. auto_view那些类型的附件是允许直接通过 .mailcap 浏览的？

    
    auto_view text/html




	
  8. move这也是一个提示性变量。它是确定当你退出时，是否提示你把信件从 spool 移动到的 mbox 文件。

    
    set move=no




	
  9. ascii_chars当 Mutt 用 thread 方式显示时，是否用纯 ascii 表示树状列表。

    
    set ascii_chars=yes


如果设置了就是这个样子：
![mutt-ascii](http://www.kreny.com/images/mutt-ascii.png)

	
  10. include回信时是否包含原文。

    
    set include




	
  11. indent_str回信的引文之前插入那个符号？

    
    set indent_str="> "




	
  12. my_hdr设置你自己的邮件头。比如我想让信件看上去是从 wang-y01@mails.tsinghua.edu.cn 发出的，而不是从 wy@wangyin.com 发出的。因为 wangyin.com 是我自己设置的主机名，不是注册的合法域名。我想让别人看到我的信是从我的清华信箱发出的，让他们直接回信到我的清华信箱，就这么干：

    
    my_hdr From: wang-y01@mails.tsinghua.edu.cn




	
  13. 打分新信件+4分，爸爸(w2r007)发来的 +2，主题包含“通知”的+2，主题包含 “Circulation” +3, 已经标记删除的 -5，上次没有读的 +1，包含 “believe”的 -10(垃圾广告！)。

    
    score "~N" +4
    score "~f w2r007" +2
    score "~s 通知" +2
    score "~s Circulation" +3
    score "~D" -5
    score "~O" +1
    score "~s believe" -10




	
  14. sort排序方式。可以是

    
       date
       date-sent
       date-received
       from
       mailbox-order (unsorted)
       score
       size
       subject
       threads
       to


几种方式，每种方式可以在前面加一个 "reverse-" 前缀表示反方向排序。我一般按分数排序：

    
    set sort=score




	
  15. sort_aux当用 thread 排序方式时，我们对各个 thread 的相对排序顺序。

    
    set sort_aux=date




	
  16. pager_stop如果设置，那么你在pager(就是你看信的内容的窗口里)翻页时，如果翻到最后，再按往下翻也不会翻到下一封信件。如果不设置就会自动翻到下一封信。

    
    set pager_stop




	
  17. fast_reply如果设置，当你按 "r" 回信时，就不会再提示你输入回信地址和主题，直接进入编辑模式。

    
    set fast_reply




	
  18. resolve当你按 "t" 或者 "D" 之类的标记操作时，是否自动把光标移动到下一封信件。

    
    set resolve=yes




	
  19. alias_file当你在 index 里按 "a" 为来信者取别名时，使用哪一个别名文件保存这个别名。

    
    set alias_file=/home/wy/.mutt.alias




	
  20. record你发出的邮件保存到那个信箱文件？比如可以像我这样每个月发出的信件放在不同的文件里。

    
    set record="~/Mail/=sent-mail-`date +%Y-%m`"




	
  21. charset你的终端支持哪一种编码的显示？这个必须和你的终端编码一样。

    
    set charset="gb2312"




	
  22. send_charset发信时可以使用的字符集。只有当前面的字符集不能正确表示信件内容时才 会使用后面的。比如，如果你像下面这样设置，你的信件如果全是英文，那么信件就会被设置为 us-ascii 编码，如果出现了法语字符，那么就会用 iso-8859-1，如果出现了汉字就会用 gb2312，如果以上都不是，那么就用 utf-8。

    
    set send_charset="us-ascii:iso-8859-1:gb2312:utf-8"




	
  23. wait_key当外部程序退出时，是否要求用户按一个键才返回。这在察看某些shell命令输出时是比要的，否则它们一下就消失了。

    
    set wait_key=yes




	
  24. confirmappend当你要把信件存到另一个信箱，而这个信箱已经存在时，是否提示附加？

    
    set noconfirmappend




	
  25. edit_headers是否把邮件头也放在编辑器里可以修改？

    
    set edit_headers=no




	
  26. pager_index_lines当你在用 pager 看信件时，在 index 留出多少行显示邮件列表？

    
    set pager_index_lines=4


比如我留下4行显示列表，其它的用来显示正文： ![mutt-indexpager](http://www.kreny.com/images/mutt-indexpager.png)

	
  27. subscribe告诉 Mutt 你已经订阅了那些邮件列表(mailing-list). 这有助于 Mutt 判断那些信件是邮件列表转过来的，避免你错误的回复到别人的私人信箱。也避免别人回复到你的私人信箱。

    
    subscribe fvwm@fvwm.org


之后，收到的 To: 是 fvwm@fvwm.org 的信件看起来是这样：

![mutt-list](http://www.kreny.com/images/mutt-list.png)

地址前面那个 "L" 表示这是一个邮件列表转过来的。你看到以后就不要按 "r" 回信，这样会回到别人的私人信箱去。按 "L"，就可以回复到邮件列表地址，这里就是 fvwm@fvwm.org。




### Mutt中文FAQ


以下是一些常见问题和解决方法。很多是我遇到的一些不能直接连接国外网络，没有自己的域名和邮件服务器的人遇到的问题。



	
  1. 怎样才能让我发出的信件使用我的POP邮箱的地址，而不是 root@myhost.com 这样的地址？用 my_hdr 把你的 From: 设置为你想要的地址就行了。比如我是这样设置的：

    
    my_hdr From: wang-y01@mails.tsinghua.edu.cn


注意 From: 的冒号之后有空格！

	
  2. 怎样让 Mutt 显示日期等为中文？

    
    set locale="zh_CN"




	
  3. 发出的信件为什么设置了错误的 charset？别人的程序不能正确显示我的中文信件！把 gb2312 编码加到你的 send_charset. 就像这样最好：

    
    set send_charset="us-ascii:iso-8859-1:gb2312:utf-8"




	
  4. 收到一些中文信件全部显示为 "???"这是因为某些 email 客户端，比如清华大学 mails.tsinghua.edu.cn 的WWW界面客户端 没有设置字符编码，你看看邮件头(按h)，是不是有个

    
    Content-Type: text/plain


但是后面没有说 charset="GB2312"? Mutt 遇到这种没有设置 charset 的邮件就会使用 "us-ascii"，所以如果你想让这种信件可以正确显示，就把 "us-ascii" 设置为 "gb2312" 的别名：

    
    charset-hook ^us-ascii$ gb2312


注意 "us-ascii" 中间的连字号！

	
  5. 可是仍然有邮件标题乱码呢！看看你的 $spool 里那个乱码的信件是不是有类似如下内容：

    
    Subject: =?iso8859-1?B?U29oddCj09HCvDq587Dg09DQwrPJ1LG808jro6E=?=


Chinaren 等服务器发出来的信件使用了 quoted-printable 的 subject，而且设置编码为 "iso8859-1"，这显然是错误的。

对付这个错误的办法是把 iso-8859-1 变成 gb2312 的别名：

    
    charset-hook ^iso-8859-1$ gb2312


注意 "iso-8859-1" 中间的连字号！

如果仍然有信件乱码。干脆用

    
    charset-hook .\* gb2312


把所有信件都用 gb2312 显示。

	
  6. 可是这样设置之后 evolution 发过来的 subject 为 utf-8 编码的邮件标题乱码！那就把不是 utf-8 的编码都映射到 gb2312:

    
    charset-hook !utf-8 gb2312




	
  7. 怎样配置 fetchmail?fetchmail 的配置非常简单。如果只是一个人用的话，可以这样设置：比如，我在我的 $HOME 目录编辑了一个 .fetchmailrc:

    
    set daemon 60
    poll mails.tsinghua.edu.cn
    protocol POP3
    user "wang-y01"
    password "wang-y01的密码"
    poll smth.org
    ....
    ....


然后把 fetchmail 写到我的shell启动脚本里:

    
    ! ps aux | grep -q fetchmail && fetchmail &


fetchmail 启动后成为一个 daemon, 每分种帮我检查所有邮箱里的邮件，收回来，并且转发到本地信箱。修改上面那个 "60" 就可以改变检查时间间隔。

如果不想让 fetchmail 删除服务器上的文件，而且每次只取新的信。就在配置文件里加上：

    
    keep
    uidl




	
  8. 我不想用 fetchmail，能不能直接收回 POP 信件啊？如果你的 Mutt 编译时加入了 POP 功能，那么你可以直接从 POP 服务器收邮件而不用借助于 fetchmail. 把类似这些行加入 ~/.muttrc

    
    set pop_user=wang-y01
    set pop_pass="wang-y01的密码"
    set pop_host="pop://mails.tsinghua.edu.cn"


也可以一次性输入所有内容：

    
    set pop_host="pop://wang-y01:wang-y01的密码@smth.org"


在 Mutt 里按一下 "G" 就可以取邮件了。

	
  9. 怎样处理多个 POP3 信箱？如果你有多个POP信箱，你可以设置一些方便的宏把POP信件收到你信箱里。举个例子，就像我这样：

    
    macro index ,shredder ":set pop_host=\
     \"pop://shredder:shredder的密码@smth.org\"\r\
     <fetch-mail>"
    
    macro index ,sk8er ":set pop_host=\
     \"pop://sk8er:sk8er的密码@smth.org\"\r\
     <fetch-mail>"
    
    macro index ,ts ":set pop_host=\
     \"pop://wang-y01:wang-y01的密码@mails.tsinghua.edu.cn\"\r\
     <fetch-mail>"
    
    macro index ,g ",shredder,sk8er,ts"


这样，我只要按 ,shredder 就可以收我在 smth 上 shredder 的信件，只要按 ,sk8er 就可以收我在 smth 上 sk8er 的信件，只要按 ,ts 就可以收 mails.tsinghua.edu.cn 的信件，只要按 ,g 就可以收取我所有 POP 信箱的信件了。

	
  10. 怎样直接访问 POP3 信箱?除了上面的方法，你还可以直接访问 POP3 信箱。比如，我可以直接按 "c" 切换到信箱 pop://sk8er:sk8er的密码@smth.org就可以浏览 pop 的信件了。切换到其它信箱就浏览不同的 pop。如果你嫌按键太多可以自己定义一个宏。这是同步操作，你如果在这个信箱里删除一封信件，mutt 就会删除你 pop3 服务器上的信件。你不删它也不删。邮件太多时这样效率很低，每次都要取所有邮件头，就像 Foxmail 的“远程邮件管理”。所以最好在那种不想取回信件，而想直接删除垃圾邮件的时候用这个办法。

	
  11. 怎样处理邮件列表？参看[subscribe](http://www.kreny.com/docs/mutt.html#subscribe)命令。

	
  12. 我按 "d" 的时候邮件被直接标记删除了，怎样才能把删掉的信件都移到一个“垃圾箱”呢？你 只要把信件用 save-message 函数保存到你的垃圾箱，比如 ~/Mail/Trash，信件会被自动做上 "D"(删除) 标志。为了让 "d" 可以保存到垃圾箱，你可以把 "d" 键绑定到一个 宏。但是如果你要删除垃圾箱里的邮件，这个宏会再次把垃圾箱的邮件存储到垃圾箱，产生循环。所以你应该使用 folder-hook 在垃圾箱里把 "d" 恢复到原来的 delete-message 函数，而在其它信箱使用那个宏。现在你可以用以下设置得到一个“垃圾箱”的功能。第一次按 "d" 时有可能会被讯问是否建立这个信箱(Trash).

    
    folder-hook . 'macro index d "~/Mail/Trash\r"'
    folder-hook ~/Mail/Trash 'bind index d delete-message'




	
  13. 当收到的邮件的 header 有很多项目时，我的 pager 里全都是邮件头。怎样才能只看到某些我想看的邮件头呢？你可以用 ignore 忽略你不想看到的邮件头，如果 ignore \*，你就可以忽略所有邮件头。用 unignore 可以恢复显示被忽略的邮件头。所以一个简单的办法就是先把所有邮件头忽略，然后放出你想看的那几个。看下面的设置。我的 sent.\*(发件箱) 里只显示 To: Subject: Date: 三项。而在其它信箱就显示 From: Subject: X-Mailer: Date: 这几项。

    
    folder-hook . "ignore \*; unignore from subject X-mailer date"
    folder-hook sent.\* "ignore \*; unignore to subject date"


你还可以指定邮件头显示的顺序：

    
    hdr_order from to subject date




	
  14. Mutt 怎么使用地址簿呢？你可以用 alias 来实现一个地址簿。alias 命令的形式是这样的，举个例子：

    
    alias wy Wang Yin <wang-y01@mails.tsinghua.edu.cn>


alias 是命令，wy 是别名，Wang Yin <wang-y01@mails.tsinghua.edu.cn> 是一个标准的 email 地址。这样，如果你在 index 里按 "m"，在 To: 的提示下输入 "wy"，就可以发信给 Wang Yin <wang-y01@mails.tsinghua.edu.cn> 。

在 To: 的提示下按 Tab 就可以显示联系人列表，然后你可以移动光标选择联系人。

如果你有很多 alias 要写，最好把它们写到另外一个文件，比如叫 .mutt.alias. 然后在 .muttrc 里加上:

    
    source ~/.mutt.alias


你还可以设置一个变量：

    
    set alias_file=~/.mutt.alias


这样你在 index 里按 "a"，就可以把来信人加入到这个 alias 文件了。

	
  15. Mutt 如何处理 HTML 附件？Mutt 可以处理任何类型的附件。因为它可以调用合适的程序来处理它们。为了直接在 mutt 的窗口里显示 HTML，你只需要在 ~/.mailcap 文件加入：

    
    text/html; lynx --dump %s; nametemplate=%s.html; copiousoutput


在 ~/.muttrc 加入：

    
    auto_view text/html




	
  16. Mutt 如何处理 Word doc 附件。清华大学总是喜欢发送含有 doc 附件的通知。真是让人ft。现在有一个完美的解决方案了：使用 wvware 把 doc 转成 HTML 嵌入mutt里。wvware 可以在 [http://www.wvware.com/](http://www.wvware.com/)免费得到。

    
    wvHtml --charset=gb2312 your.doc your.html


就可以把doc转成 HTML。经测试，能够正确处理汉字和图片。你可以让[mutt](http://www.kreny.com/docs/mutt_frame.html)调用 wvHtml 在自己的窗口里直接显示转换的 doc 文档。只需要在 ~/.mailcap 文件加入：

    
    application/msword; wvHtml --charset=gb2312 %s - | lynx --dump -stdin;
    nametemplate=%s.html; copiousoutput
    
    text/html; lynx --dump %s; nametemplate=%s.html; copiousoutput


在 ~/.muttrc 加入：

    
    auto_view text/html application/msword


这样你的 mutt 看一个 doc 的时候就像这个样子：
![mutt-wvware](http://www.kreny.com/images/mutt-wvware.png)

	
  17. 我想在 Mutt 里使用 Emacs 怎么办？Emacs 是一个非常强大的编辑器，所以你肯定会希望能在 Mutt 里使用 Emacs。你可以选择两种方式:

	
    1. 一种方式是直接在 Mutt 的终端里使用非图形界面的 Emacs (emacs -nw)。你只需要在 .muttrc 设置：

    
    set editor="emacs -nw"


这样会启动一个新的 Emacs。如果你的 Emacs 配置加入了大量扩展，这个启动时间是相当长的，你不希望每回一封email就等上10秒等Emacs启动吧？有 一个办法可以跳过冗长的 Emacs 扩展。只需要把你的 .emacs 里耗时的部分放在一个条件语句里。比如，我就把 desktop 和 session 放在了一个条件语句里启动。如果知道编辑的文件名叫做 "/tmp/mutt-..." 那我们就知道是 mutt 在调用 Emacs，所以我就不加载 desktop 和 session 这种费时间又没用的东西。

    
    (unless
        (catch 'found
          (dolist (arg command-line-args)
     (if (string-match "^/tmp/mutt-" arg)
         (throw 'found t))))
    
      ;; load desktop
      (load "desktop")
      (desktop-load-default)
      (desktop-read)
    
      ;; load session
     (require 'session)
     (add-hook 'after-init-hook 'session-initialize)
     (setq desktop-globals-to-save '(desktop-missing-file-warning))
    
      ;; start server
      (server-start)
    )




	
    2. 一种方式是使用 emacsclient 发送到 GUI 的 Emacs 服务器编辑。这种方式可以使用一个已经启动的 Emacs，启动非常快速。但是我不是很喜欢这种方式，因为我不想离开 Mutt 的终端到 Emacs 的窗口，编辑完了还要切换窗口。看[这幅图](http://www.kreny.com/images/mutt-emacsclient.png)。先来看看 Emacs 的设置，启动 Emacs 后，你可以使用 server-start 启动 Emacs 服务器。你也可以把

    
    (server-start)


加入到你的 .emacs 文件，这样 Emacs 启动时自动就启动了服务器。在 .muttrc 里加入

    
    set editor=emacsclient


这样 Mutt 在要发送邮件时，就把需要编辑的东西送到已经启动的 Emacs 里。编辑完了之后你按 C-x #，控制会转回到 Mutt.




	
  18. 我不能直接连国外，sendmail必需通过 mails.tsinghua.edu.cn 转发，但是 sendmail 不能通过 ESMTP 验证怎么办？由 于清华大学网络中心的限制，一般同学不能直接连接国外的服务器。这样 sendmail 就不能直接将邮件发送到目的地。我们需要依赖国内的 邮件服务器来转发到目的地。但是现在国内的smtp邮件服务器通常需要 SMTP 验证才能帮你转发邮件。比如 mails.tsinghua.edu.cn, 这是一种防止别人利用自己主机发送垃圾邮件的办法。sendmail 怎样才能通过 SMTP 身份验证呢？sendmail 的网页上说有办法。可是我搞了一天还是没有搞定。而且 sendmail 是以安全漏洞著称的。所以我决定换用 Postfix。qmail 也很好，但是我不知道怎么让 qmail 通过 AUTH SMTP 转发, 如果有人知道请告诉我。postfix 是一个可以取代 sendmail 的邮件服务器。它在普通机器上可以达到 sendmail 3 倍的吞吐率。而且相当安全。它可以在 www.postfix.org 下载安装过程如下：

	
    1. 编译的时候你需要让 postfix 支持 SASL 验证，使用以下选项编译：

    
    % make makefiles CCARGS="-DUSE_SASL_AUTH -I/usr/local/include" \
            AUXLIBS="-L/usr/local/lib -lsasl"


然后安装

    
    % make; make install




	
    2. 为了 postfix 能够正确发送本地邮件，请在 /etc/postfix/main.cf 加上：

    
    myhostname = tu140066.tsinghua.edu.cn
    mydestination = wangyin.com, $myhostname, localhost.$mydomain


$myhostname 指明了你的主机域名，清华大学的网络给了每个人一个域名，其实就是 tuxxxxxx.tsinghua.edu.cn, xxxxxx 就是你的 IP 后面的数字，比如我的IP是166.111.140.66, 所以我的域名是 tu140066.tsinghua.edu.cn.

$mydestination 指出哪些地址是认为是你自己的地址。你应该把你的机器名(我的是 wangyin.com)，$myhostname, $localhost.$mydomain 加进去。

	
    3. 为了能够使用 SASL 验证登录，把这些行加到 /etc/postfix/main.cf

    
    smtp_sasl_auth_enable = yes
    smtp_sasl_password_maps = hash:/etc/postfix/sasl_passwd
    smtp_sasl_security_options =
    relayhost = mails.tsinghua.edu.cn




	
    4. 编辑口令文件 /etc/postfix/sasl_passwd。加入一行：

    
    Your.Relay.Server           your_auth_login_name:Your_PassWord


比如我的口令文件是这样的：

    
    mails.tsinghua.edu.cn          wang-y01:aDF2m@3d$q=+


当然密码不是那个 :P

	
    5. 把口令文件转成 Berkeley DB 格式：

    
    #postmap hash:sasl_passwd




	
    6. 启动你的 postfix 服务器

    
    postfix start










