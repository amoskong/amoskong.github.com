---
author: amosk
comments: true
date: 2013-07-04 02:18:57+00:00
layout: post
slug: '%e5%9c%a8linux%e4%b8%8b%e4%bd%bf%e7%94%a8qemu%e8%99%9a%e6%8b%9f%e6%9c%bau%e7%9b%be%e8%ae%a4%e8%af%81%e7%bd%91%e9%93%b6'
title: 在Linux下使用QEMU虚拟机U盾认证网银
wordpress_id: 969
categories:
- Linux
---

这里以招商银行为例， 使用 lsusb 命令查看当前usb状态，然后将招商银行U盾插入主机USB插口。再通过lsusb查看新设备的的USB串号（这里查找到的是1483:c007）。

` # lsusb
Bus 003 Device 007: ID 1483:c007
......`

启动QEMU虚拟机，使用（-usbdevice host:U盾串号）把主机上的U盾指定给虚拟机使用

` # qemu --enable-kvm /images/winXP-32-virtio.qcow2 -m 2000 -vnc :10 -usbdevice tablet -net nic,model=rtl8139 -net tap -usbdevice host:1483:c007[![Screenshot from 2013-07-04 09:34:18](http://amosk.info/blog/wp-content/uploads/2013/07/Screenshot-from-2013-07-04-093418-300x255.png)](http://amosk.info/blog/wp-content/uploads/2013/07/Screenshot-from-2013-07-04-093418.png)`
