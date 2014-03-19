---
author: amosk
comments: true
date: 2008-12-02 12:02:00+00:00
layout: post
slug: virtualbox%e6%96%87%e4%bb%b6%e5%85%b1%e4%ba%ab%e8%ae%be%e7%bd%ae
title: VirtualBox文件共享设置
wordpress_id: 302
categories:
- Linux
- Web
---

![](http://www.by-w.com/uploadpic/08084/vbox_logo2_gradient.png)


刚在虚拟机里装了Fedora10，以前使用NAT进行网络设置，虚拟机里只需要dhcp就行了。网络设置成功，就可以使用scp在主机和虚拟主机之间传送文件，以前是做了n多的alias，使用起来还算方便，不过文件较大时就麻烦了。

于是考虑使用VirtualBox自带的文件共享。记得梅研涛以前虚拟了一个Windows，用鼠标直接把文件夹拖动到Windows桌面就共享了，这次我安装的Fedora，只使用命令行。

1.为虚拟主机安装VBoxGuestAdditions，这样才能支持文件夹共享。
1) 安装完Fedora后，启动虚拟主机，在主机窗口菜单，Device -> install guest additions，点击弹出一个窗口，上面显示VBoxGuestAdditions的镜像URL，并下载。当然也可以自己从网上下载安装镜像。
2) Devices -> mount cdrom -->cdrom image 然后选择下载到外边主机的 VBoxGuestAddition.iso
3) 在虚拟主机里面mount  /dev/cdrom /mnt/cdrom
4) 进入/mnt/cdrom目录，输入# sh VBoxLinuxAdditions.run，安装程序。
5)关机，执行完下面的共享文件夹设置。等下次启动vboxsf模块会自动加载加载到虚拟主机。

2.设置共享文件夹
1) 点击Settings-> Shared Folders
2) 点击旁边按钮添加Host中的共享文件夹（例如 /home/kongove/code/kernel ），可以在这里设置访问权限。
3) 启动虚拟主机，在下建立共享文件夹（例如 /root/kernel）
4) # mount -t vboxsf kernel /root/kernel 挂在共享文件夹

以后使用只需执行最后的mount语句即可。这样用起来很方便，就跟在一个系统一样。
