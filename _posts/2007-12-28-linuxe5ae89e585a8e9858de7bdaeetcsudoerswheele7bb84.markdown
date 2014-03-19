---
author: amosk
comments: true
date: 2007-12-28 12:12:15+00:00
layout: post
slug: linux%e5%ae%89%e5%85%a8%e9%85%8d%e7%bd%aeetcsudoerswheel%e7%bb%84
title: linux安全配置/etc/sudoers&wheel组
wordpress_id: 168
categories:
- Linux
---

/etc/sudoers 控制哪些用户能在哪些主机上以哪些用户的身份执行哪些命令。只有此文件权限为440时才能用户才能使用sudo命令，只有root用户才能使用visudo命令修改此文件。当然也可以先添加文件写权限，然后修改，再把文件权限改回来。
此文件的一些配置规则
定义别名：
User_Alias UserName = user1,user2,kongove
Host_Alias HostName = host1,host2,221.11.20.10
Cmnd_Alias CmdName = cmd1,/bin/ls,!/sbin/reboot
UserName、HostName、CmdName为定义的别名。

缺省情况使用Defaults设置：
Defaults:UserName !lecture
默认UserName没有输出初次使用sudo的提示。

限定用户权限：
语句形式：User Host = (USER) Cmd
语意：User在Host上，以USER的身份执行Cmd命令

User可以是单个用户、%用户组、用户别名
Host可以是但个主机名\Ip、主机别名
USER可以是单个用户、多个用户名、用户别名
Cmd可以是但个命令、多个命令、命令别名

几个例句：
root ALL = (ALL) ALL
%wheel ALL = (ALL) ALL
%admin ALL = (ALL) ALL
UserName HostName = (USER) CmdName
kongove ALL =ALL,!su,!lecture

在用户名、主机名（IP）、命令前使用“！”表示非指定对象。

这里对/etc/sudoers的配置只是总结了一点点，但有这些已经可以完成简单的安全配置了。

默认情况下，任何普通用户都可以通过su命令获得root用户的


权限，对系统进行任何的操作。为了加强系统安全，Linux提供一个管理员组，只有属于这个组的用户才能使用su命令获得root权限，这个组通常为wheel。


为了实现属于wheel组的用户才具有root权限，需要两个步骤：
1、将用户添加只wheel组：usermod -G wheel username
2、修改/etc/pam.d/su， 添加
auth required pam_wheel.so use_uid

强调一点：Linux病毒少不是因为Linux不如Windows流行，而在于她的整体设计！
