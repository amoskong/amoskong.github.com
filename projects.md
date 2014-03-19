---
layout: page
title: Project
group: navigation
date: 2013-12-09 23:45:54+00:00
---

### Linux Kernel

#### [Kernel.org](http://kernel.org/)

- [Linux tree of Linus](http://git.kernel.org/?p=linux%2Fkernel%2Fgit%2Ftorvalds%2Flinux.git)
[(lkml)](http://lkml.org/)
- [Net-next tree of Davide S.Miller](http://git.kernel.org/?p=linux%2Fkernel%2Fgit%2Fdavem%2Fnet-next.git) [(netdev)](http://marc.info/?l=linux-netdev&r=1&w=3)
- [Kernel-based Virtual Machine(kvm) tree of Avi](http://git.kernel.org/?p=virt%2Fkvm%2Fkvm.git)
[(kvm)](http://marc.info/?l=kvm) [(lf-virt)](https://lists.linux-foundation.org/pipermail/virtualization/)
- [Linux-pci tree of Helgaas](http://git.kernel.org/?p=linux%2Fkernel%2Fgit%2Fhelgaas%2Fpci.git) [(pci)](http://marc.info/?l=linux-pci)

### Qemu

#### [Qemu.org](http://wiki.qemu.org/Main_Page)
- [Qemu gitWeb](http://git.qemu.org/?p=qemu.git;a=summary) [(qemu-devel)](http://lists.nongnu.org/archive/html/qemu-devel/)

#### [Linux-kvm.org](http://linux-kvm.com/)
- [Qemu-KVM gitWeb](http://git.kernel.org/?p=virt%2Fkvm%2Fkvm.git)

### Autotest

#### [Autotest.kernel.org](http://autotest.kernel.org/)
- [gitWeb](https://github.com/autotest/autoest)

### IPxe

#### [Ipxe.org](http://ipxe.org/)
[gitWeb](http://git.ipxe.org/ipxe.git) [ipxe-devel](http://lists.ipxe.org/pipermail/ipxe-devel/)

### SeaBIOS

#### [Seabios.org](http://seabios.org/)
- [gitWeb](http://seabios.org/git/?p=repositories/seabios.git;a=summary) [(seabios)](http://www.seabios.org/pipermail/seabios/)

### Netperf

#### [Netperf.org](http://www.netperf.org)
- [SvnRepo](http://www.netperf.org/svn/netperf2/) [(netperf-dev)](http://www.netperf.org/cgi-bin/mailman/listinfo/netperf-dev)

* * *

### LinuxDNA

LinuxDNA is a project that compiling the linux kernel with icc for high performance. [http://linuxdna.com](http://linuxdna.com/) My Office Email: jianjun (at) linuxdna.com

### XylFTP

XylFTP是基于linux开发的一款提供文件传输服务的系统软件，包括客户端(Java)和服务端(C)两部分，由西邮linux兴趣小组成员合作完成。

其最大特点就是轻量级，有自己的用户管理模块。

- [XylFTP客户端1.2(命令行界面)下载](http://jaist.dl.sourceforge.net/sourceforge/xylftp/xylftp-client-1.2.tar.gz)
- [XylFTP服务端1.0下载](http://www.xiyoulinux.cn/down/xylftp-server-1.0.tar.gz)
- 项目CVS地址：[https://sourceforge.net/projects/xylftp](https://sourceforge.net/projects/xylftp)
- 项目Git地址：[http://repo.or.cz/w/xylftp.git](http://repo.or.cz/w/xylftp.git)

[![](http://amosk.info/pub/images/xylftp-gui.png)](http://amosk.info/pub/images/xylftp-gui.png)

### KenOS

Write an operating system from scratch, all the tools used here are opensourced.
I only read some code, need commit some change when I've more free time ;)

- [http://code.google.com/p/kenos/](http://code.google.com/p/kenos/)
- [http://github.com/kcao/kenos](http://github.com/kcao/kenos)

### Python Pinyin Searcher(PySearcher)

用Python语言开发的一款，图形界面的汉字拼音查询工具。运行环境为: GNU/Linux，Windows等支持Python的操作系统，Python2.5以上版本，wxPython图形库。 预期用户为学习汉语拼音的外国朋友。

Git:[http://github.com/kongove/toys/tree/master/pysearcher/](http://github.com/kongove/toys/tree/master/pysearcher/)

这里还有一个从网络查找汉字五笔编码的python脚本，完全是为了自己使用。目前不支持本地查询，只有命令行。
$ ./wubi.py "要查询的汉字"
[http://github.com/kongove/toys/tree/master/wubi/](http://github.com/kongove/toys/tree/master/wubi/)

[![](http://amosk.info/pub/images/pysearcher.png)](http://amosk.info/pub/images/pysearcher.png)

### QFreeRecite

使用C++(QT库)开发的，根据人类记忆曲线规律，帮助记忆单词的工具。项目处于初级队段，目前我和梅研涛参与。
1. 字典设计灵活，词汇量大：可随时修改字典，且现在已经有近5万词汇量，足以满足绝大多数用户的需求。
2. 加入了短路记忆循环，也就是在背诵的时候按照一定时间回顾前面的词，极大地提高了记忆的效率；
3. 自动抓取难点词汇，帮助用户重点复习（Stress功能）；
4. 支持双向记忆和复习，汉－英（反向模式）和英－汉（普通模式）；
5. 背景音效和发音功能齐全，单词发音需要安装WyabdcRealPeopleTTS词库；
6. 软件体积小，依赖关系简单(CUI版需要shell和C++，GUI版需要Qt4)。

项目Git地址：[http://repo.or.cz/w/QFreeRecite.git](http://repo.or.cz/w/QFreeRecite.git)

[![](http://amosk.info/pub/images/qfrt-main.png)](http://amosk.info/pub/images/qfrt-main.png)

### Pigeons

用QT+linux开发的，一个遵循飞鸽协议的可扩展、可定制文件传输工具。 QT跨平台，支持Linux、Windows、Mac OS等操作系统，此程序可以很方便移植到其他平台。 存在问题是IPMSG协议资料太少，为制定公共标准，使用还存在一些问题。 等基本功能实现后，可以考虑扩展到外网，采用P2P方式传输文件，有一个外网服务器负责前线搭桥。

- 项目Git地址：[http://repo.or.cz/w/pigeons.git](http://repo.or.cz/w/pigeons.git)

[![](http://amosk.info/pub/images/pigeons.png)](http://amosk.info/pub/images/pigeons.png)

### Linux Processor Trace System(MyTrace)

本系统是在Linux内核环境下使用多线程技术采集相关数据，并将数据进行分析处理，得到所有进程的实时信息（包括其对文件、内存、网络等的操作），将这些信息输出到监控程序，以跟踪进程的行为所获得的记录文件为基础，以定义的规则为依据，对两者进行比较与分析，来判断是否遭到恶意攻击或病毒感染，从而达到实时监控发现病毒的目的。

于2008年夏与电信王聪等合做。

- [http://github.com/kongove/toys/tree/master/mytrace/](http://github.com/kongove/toys/tree/master/mytrace/)

[![](http://amosk.info/pub/images/mytrace.png)](http://amosk.info/pub/images/mytrace.png)

### SPyFTP

SPyFTP is short for 'Smart Python FTP'. Although SPyFTP is now just a small ftp client running in CLI, I will add more features, including GUI features, to it soon. Server side is also taken into my consideration.

这个项目是wangcong创建的，这学期对Python很痴迷，像深入一下，于是掺和了进去。如果你想参与，也很欢迎！
- 项目地址：[http://code.google.com/p/spyftp/](http://code.google.com/p/spyftp/)

### LPA

LPA(Linux Programmer Assistant)是用Gtk开发的linux程序员助手，主要功能：标准库函数及linux基本命令查询，ASCII码查询，进制转换查询，颜色值查询，文档书签管理，汉字编码查询，unicode查询等。设计中...

- 项目Git地址：[http://](http://repo.or.cz/)

### Java-Talk

用Java编程语言开发一个局域网聊天工具，具备普通聊天工具的几本通信功能，有较为良好的用户界面，方便用户操作。保证数据准确到达的前提下，尽可能降低程序对系统资源的使用，最大限度的简化程序运行所需的硬软件资源，使程序的使用性大大增强。预期实现功能有，在线用户显示、发送接收消息、用户列表更新、用户信息标识、自动回复信息、GUI图形界面等、方便用户操作的控制按钮、提示用户重要信息等。下载后，如果出错可能需要转换字符编码。windows下编译用javac -nowarn -Xlint:deprecation Ktalk.java，因为里边用到了一些过时的接口。 [http://github.com/kongove/toys/tree/master/java-talk/](http://github.com/kongove/toys/tree/master/java-talk/)

[![](http://amosk.info/pub/images/java-talk.png)](http://amosk.info/pub/images/java-talk.png)

### Escapee Game(j2me)

使用myEclipse+WTK开发，实现的是经典游戏"是男人就撑20秒"的一些基本功能，还存在一些bug，一些功能还未实现。不过想学习j2me游戏开发的人，可以读一下源码。这个程序还有很多扩展开发的空间，有时间在研究吧。

- [http://github.com/kongove/toys/tree/master/Escaper/](http://github.com/kongove/toys/tree/master/Escaper/)

[![](http://amosk.info/pub/images/game-escape1.png)](http://amosk.info/pub/images/game-escape1.png)

### XyBackup

用Bash 开发的系统备份工具。

- 项目CVS地址：[http://pigeons.cvs.sourceforge.net/pigeons/xybackup/](http://pigeons.cvs.sourceforge.net/pigeons/xybackup/)

### Small Coding in Lab 434(xiyou)

I have created a project to record those code, it'll be the newest version.

- ([http://github.com/kongove/toys](http://github.com/kongove/toys))
 
    $ ls
    book-managment-system  Escaper  fibocaii  find-proxy  java-talk  lottery  mycat  mytrace  port-search  processor-ring  pysearcher  README  s-email  wubi


* * *

#### Port Searcher


用Python编写的一个端口扫描器，调用tellib库实现。由于实现方式更底层，所以速率相当快。用户可以通过参数制定扫描IP地址、端口范围、超时大小等，灵活方便。通过发送数据来探测开饭端口的服务类型，目前可以识别HTTP、FTP、SMTP、POP、SSH等服务。有待进一步改进，后期可以考虑做个图形界面方便用户操作。

#### Processor Ring

在linux+gcc+vi环境下 ，通过进程间通信形成进程环，并传递计算Fibocaii级数系列的前N项。

#### Fibocaii


用shell编写的脚本实现输出Fibocaii级数系列的前N项。


#### Mycat


模仿linux系统自带的cat，用C编写一个mycat.c，功能与系统的cat相近。


#### s-email.sh


shell编写的，抓取指定url地址的网页中的email地址。


#### FindProxy.bat


windows下的一个批处理，通过更改网关达到搜索代理服务器的功能，当然还需配置DNS。适用于内网设置代理服务器（如：Sygate）较多时，解决临时上网问题。


#### Library Management System


大一课程设计时编写的图书管理系统。

## Document and Book

* * *

### Translation

- Free Software, Free Society
- git-email
- etc

### Book Projects

- [Lovely Python](http://wiki.woodpecker.org.cn/moin/ObpLovelyPython)
- [Zeuux Hand Book](http://www.zeuux.org/community/zeuux-handbook.cn.html)
- [Learning Tcpdump](http://amosk.info/pub/doc/learning-tcpdump.cn.html)
- [Learning Mysql](http://amosk.info/pub/doc/learning-mysql.cn.html)
- [Learning Git](http://amosk.info/pub/doc/learning-git.cn.html)
- [Learning Apache](http://amosk.info/pub/doc/learning-apache.cn.html)

[![](http://amosk.info/pub/images/zeuux-book.jpg)](http://amosk.info/pub/images/zeuux-book.jpg)
[![](http://amosk.info/pub/images/lovely-python.jpg)](http://amosk.info/pub/images/lovely-python.jpg)


### Writing

- [Write to kernel newbies](http://amosk.info/pub/doc/kernel-newbies.html)
- [Read source code by Vim+Ctags+Cscope](http://amosk.info/pub/doc/vim-ctags-cscope-source.html)

