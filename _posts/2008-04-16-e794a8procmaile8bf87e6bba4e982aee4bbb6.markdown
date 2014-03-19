---
author: amosk
comments: true
date: 2008-04-16 14:50:26+00:00
layout: post
slug: '%e7%94%a8procmail%e8%bf%87%e6%bb%a4%e9%82%ae%e4%bb%b6'
title: 用procmail过滤邮件
wordpress_id: 225
categories:
- Linux
---

这几天一直在忙Pigeons没写博客，上周见梅延涛用客户端把邮件分类便于查收，我在Evolution上也设置过比较简单。不过在现在用mutt，如果能配置一下就好了。于是摸索了一下，在这里做一总结。

首先说mutt的信箱，可以是一个文本文件，也可以是目录（包含三个子目录cur,new,tmp）。在配置文件时注意用/区分，如文本文件用file，目录file/  。我配置中就由于这个反复实验了n次~

我用的是mutt+procmail+mstmp+getmail，自习看我的配置文件，发现前面根本没用procmail，而是直接放到~/Mailinbox/里

原来~/.getmail/getmailrc的[destination]：

[destination]
type = Maildir
path = ~/Mail/inbox

新~/.getmail/getmailrc的[destination]：

[destination]
type=MDA_external
path=/usr/bin/procmail
unixfrom=true
下来就是配置procmail了，配置文件~/.procmailrc （注意它的权限不能大于640，否则也会失败）

PATH=/bin:/sbin:/usr/bin:/usr/sbin
SHELL=/bin/bash
MAILDIR=$HOME/Mail
DEFAULT=$MAILDIR/inbox
LOGFILE="/var/log/procmail.log"

:0
* ^From.*noreply@googlegroups.com
comp.lang.c
#将来自noreply@googlegroups.com的邮件保存到~/Mail/comp.lang.c （这是一个文本文件）
:0
* .*zeuux-universe@zeuux.org   #这里没有用From是因为有些来自哲思的邮件是抄送到哲思的这样就不会有遗漏了
zeuux
#将来自zeuux-universe@zeuux.org的邮件保存到~/Mail/zeuux（这是一个文本文件）
:0
* .*linux-kernel@zh-kernel.org  #这里的“.*”代表任意多少字符串
zh-kernel
:0
* ^From.*billgates@microsoft.com #Billgates的邮件直接性滚蛋~~
/dev/null
:0          #最后的这个配置就是指如果上面分类剩下的信件全扔到inbox里（inbox是个文件夹，有三个子目录new,tmp,cur）
* .* inbox
# 黑名单（垃圾邮件）
:0:
* ^From.*badguy
/dev/null

关于.procmailrc的格式，可以通过man 手册得知，在网上也有一大堆资料。我这里只是一个简单的分类，通过更详细的参数可以起到较强的过滤作用。邮件服务器的垃圾、不安全等邮件过滤就用procmail。很明显配置文件比图形化工具功能强大，这也正是我探索的目的。这个过程中也对以前mutt的配置更加了解，很好~

BTW：如果不会用mutt的地址薄，就得手动输入邮箱地址或者复制-粘贴，比较麻烦。在任意新建上按“a”就能邮件的发件人保存到地址薄。为了方便管理，在~/.muttrc里我加了一句 source ~/.muttrc.a  这样就可以把地址薄独立出来。

文件格式如：

alias  linus Linus\ torvalds  <torvalds@linux-foundation.org>

alias xylinux 西邮Linux兴趣小组 <xiyoulinux@googlegroups.com>

在发邮件输入邮件地址时，输入xylinux就会自动添加xiyoulinux@googlegroups.com，当然也可以用table键去补全、查找。这里的xyllinux只是为了方便用户输入，邮件中地址前面的用户仍为“西邮Linux兴趣小组”。

以前

alias xiyoulinux <xiyoulinux@googlegroups.com>

alias 西邮Linux兴趣小组 <xiyoulinux@googlegroups.com>

输入都不方便，现在就能提高效率了。在这个文本里，可以用\来表示特殊字符，如空格"\ "。
