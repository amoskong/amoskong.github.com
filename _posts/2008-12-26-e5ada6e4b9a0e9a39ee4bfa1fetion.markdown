---
author: amosk
comments: true
date: 2008-12-26 12:46:13+00:00
layout: post
slug: '%e5%ad%a6%e4%b9%a0%e9%a3%9e%e4%bf%a1fetion'
title: 学习飞信(fetion)
wordpress_id: 310
categories:
- Linux
- Web
---

![fetion](http://www.fetion.com.cn/images/v7/llogo.gif)

飞信算是中国移动推出的一款新业务吧，我昨天才注册了帐号 :)

Linux下使用飞信有很多方式，可以安装pidgin的插件，也可以安装其他客户端。

pidgin的飞信插件最新是v0.98，可以从sourceforge.net上下载到源代码

($ cvs -d:pserver:anonymous@fetion.cvs.sourceforge.net:/cvsroot/fetion co fetion)。

不过作者从10.6好后好像再没有更新过，也没有发布新的版本，作者好像也要开发python的飞信客户端。

pidgin插件安装：

下载libfetion.so，把它放置到 $HOME/.purple/plugins/ 或者/usr/lib/purple-2/或者/usr/local/lib/purple-2/，然后打开pidgin(版本不能低于2.4)，配置帐号即可。这里只需要配置手机号码和密码即可。

下载地址：http://forum.ubuntu.org.cn/download/file.php?id=49104

![libfetion](http://www.libfetion.cn/picture%5Cv8%5CLibFetion.png)

还有一个由邓东东主持开发的飞信应用程序开发库LibFetion，其大部分代码使用C编写，支持所有POSIX兼容的操作系统，现在貌似移植到了很多平台。基于这个库，开发了一个linux的客户端，还有其他平台的客户端，最新版本v0.9.1。

下载地址：http://www.libfetion.cn/demoapp_download.html

(包括Mac OS X,Windows,IPhone,Window Mobile等平台)

编译安装所需要的软件包：qt4 automake libc-dev g++ libcurl3-dev libqt4-dev qt4-dev-tools

解压：$ tar -zxvf linux_fetion-v0.9.1.tar.gz

编译命令：

$ cd linux_fetion

$ qmake

$ make

运行：$ ./linux-fetion

还有，我们可爱的cocobear也正在开发一个纯Python的飞信库。期待看到源码...

了解更多：http://cocobear.info/blog/?s=fetion

邓东东的LibFetion里的一些接口：

lib: 目录

libfetion_32.a  libfetion_64.a

libfetion: 目录

common.h  datastruct.h  event.h  fxconfig.h  libfetion.h

在编写程序是只需要(#include "libfetion/libfetion.h")即可调用相关接口。

初始化： fx_init();

设置代理： fx_set_proxy(&proxy);

设置登录状态： fx_set_login_status(FX_STATUS_OFFLINE);

登录： fs_login(args.from, args.passwd);

给自己发送消息： fs_send_sms_to_self(args.message);

给指定手机号发送消息： fs_send_sms_by_mobile_no(p, args.message);

给指定飞信号发送消息： fs_send_sms(uid, args.message);

登出： fx_loginout();

关闭网络连接： fx_close_network();

这里只是列出了常用的几个接口，参数类型也没有具体介绍，了解更多可以查看:

http://www.libfetion.cn/libfxAPI/index.html

这里（http://blog.solrex.cn/articles/diy-free-weather-forecast-sms.html）有一篇关于，使用LibFetion库实现，定制自己的免费天气预报短信的文章。
