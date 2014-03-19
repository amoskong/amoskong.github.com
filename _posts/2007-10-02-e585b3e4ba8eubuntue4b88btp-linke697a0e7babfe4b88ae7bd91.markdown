---
author: amosk
comments: true
date: 2007-10-02 12:05:02+00:00
layout: post
slug: '%e5%85%b3%e4%ba%8eubuntu%e4%b8%8btp-link%e6%97%a0%e7%ba%bf%e4%b8%8a%e7%bd%91'
title: 关于Ubuntu下TP-link无线上网
wordpress_id: 109
categories:
- Linux
---

小康用的是无线路由上网，机子上只要插了一个TP-link321，比较方便而且速度还可以。和win下一样，Ubuntu也得装网卡驱动。

1. 下载、编译安装必须的软件包

wget [http://rt2x00.serialmonkey.com/rt73-cvs-daily.tar.gz](http://rt2x00.serialmonkey.com/rt73-cvs-daily.tar.gz)

tar -xvzf rt73-cvs-daily.tar.gz

sudo aptitude install build-essential linux-headers-`uname -r`cd rt73-cvs-yyyymmddhh/Modulesudo

make sudo

make install

2. 修复module冲突<!-- more -->

sudo modprobe -r rt73usb

sudo modprobe -r rt2570

sudo modprobe -r rt2500usb

sudo modprobe -r rt2x00lib

编辑blacklist文件：

sudo nano /etc/modprobe.d/blacklist加入：

# Blacklist rt73usb, as it is a non-functional beta module which conflicts with the working rt73 module.

blacklist rt73usb

# Blacklist rt2570, as it causes conflicts with rt73

blacklist rt2570

# Other modules that break rt73

blacklist rt2500usb

blacklist rt2x00lib

安装模块

sudo modprobe -v rt73

3. 配置网络接口

sudo nano /etc/network/interface加入：

auto rausb0 iface rausb0inet dhcp  pre-up

ifconfig rausb0 up pre-up

iwconfig rausb0 essid “YOUR_ESSID”

按照上面的帮助一步一步操作下来还是不能识别，重启后无线网卡识别了，不过还是不能拨号。于是又用图形界面继续配置了密码等信息，不一会就正常拨号了。

建议在命令行安装驱动，等网卡识别了，再在图形界面配置用户名密码等信息。
