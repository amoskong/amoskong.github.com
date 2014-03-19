---
author: amosk
comments: true
date: 2007-12-10 14:40:24+00:00
layout: post
slug: '%e5%9c%a8linux%e4%b8%8b%ef%bc%88ubuntu%ef%bc%89%e8%a7%a3%e5%86%b3%e6%88%91%e4%bb%ac%e5%ad%a6%e6%a0%a1%e7%9a%84drcom%e5%ae%a2%e6%88%b7%e7%ab%af%e4%b8%8a%e7%bd%91%e9%97%ae%e9%a2%98'
title: linux（ubuntu）下drcom客户端上网
wordpress_id: 159
categories:
- Linux
---

1.安装编译环境：
sudo apt-get install build-essential libssl-dev


2.安装linux-headers
sudo apt-get install linux-headers-`uname -r`
uname -r是命令输出为：例如我的为2.6.15－28－686
核心是2.6.15 系统版本是28
686说的是我的cpu是p4
这个是升级后的，系统默认安装的是386


3.下载Dr.com1.3.2
下载地址： [http://sourceforge.net/projects/drcom-client](http://sourceforge.net/projects/drcom-client)


4: 安装：
tar －zxvf drcom-1.3.2.tar.gz
cd drcom-1.3.2/
注意：
修改安装程序中login.c,logout.c,passwd.c.watchport.c
这4个文件最开始的include语句中有一句 #include <openssl/md5.h> 改成 #include <md5.h>
否则的话你还需要安装一个libssl包，这个包安装盘里可是没有的-_.-+
make
sudo make install
5.配置：
sudo vi /etc/drcom.conf   （留空的不需要填写）


__________________________________begin

username=11100068969#用户名
password=126223#密码
mac=00:15:58:65:3B:FC#ifconfig查看硬件地址<!-- more -->
nic0=192.168.0.228#dhcp自动获得的ip
nic1=
nic2=
nic3=
dnsp=221.11.1.67#网通dns
dnss=221.11.1.68#次dns
dhcp=hostip=
servip=221.11.20.10
hostport=
servport=
hostname=
winver=
winbuild=
servicepack=
autologout=0

-----------------------------------------end

6.呵呵，现在就可以上网了

登录：
sudo drcomd
开机输入一次就可以
登陆
drcomc login
如果出现以下信息，说明登录成功：
Login succeeded

退出：
drcomc logout
Logout succeeded

原文见：http://bagh0662.bokee.com/viewdiary.15835207.html
