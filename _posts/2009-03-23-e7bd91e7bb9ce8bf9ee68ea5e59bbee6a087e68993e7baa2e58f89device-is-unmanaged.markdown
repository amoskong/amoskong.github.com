---
author: amosk
comments: true
date: 2009-03-23 08:49:57+00:00
layout: post
slug: '%e7%bd%91%e7%bb%9c%e8%bf%9e%e6%8e%a5%e5%9b%be%e6%a0%87%e6%89%93%e7%ba%a2%e5%8f%89device-is-unmanaged'
title: 网络连接图标打红叉(device is unmanaged)
wordpress_id: 324
categories:
- Linux
---

Fedora10安装的好几个机器都是网络设置图标打叉，还以为是BUG，上次给一朋友直接在网上复制了个网络接口配置文件就好了，当时也没仔细对比文件差异。上次我的Ubuntu升级软件、安装UbuntuStudio后也出现这个问题，但网络连接没有任何问题也就没关。今天突然发现有下面这个解决方法。

当然其他问题也可能导致图标打红叉，如没有网卡驱动、没有激活网络、没有配置等，上面是没有设置网络管理选项带来的问题。

Ubuntu网络连接图标打红叉，但通过命令行可以配置网络。将下面文件的managed值由false改为true，重启即可！

sudo vim /etc/NetworkManager/nm-system-settings.conf
[main]
plugins=ifupdown,keyfile
[ifupdown]
managed=true

Fedora10网络连接图标打红叉，但通过命令行可以配置网络。修改网络连接文件，添加 NM_CONTROLLED=yes，重启网络即可。

sudo vim /etc/sysconfig/network-scripts/ifcfg-eth0
..
NM_CONTROLLED=yes
...
