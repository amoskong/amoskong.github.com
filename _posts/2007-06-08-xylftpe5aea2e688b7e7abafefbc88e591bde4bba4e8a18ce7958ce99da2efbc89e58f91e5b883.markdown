---
author: amosk
comments: true
date: 2007-06-08 14:08:04+00:00
layout: post
slug: xylftp%e5%ae%a2%e6%88%b7%e7%ab%af%ef%bc%88%e5%91%bd%e4%bb%a4%e8%a1%8c%e7%95%8c%e9%9d%a2%ef%bc%89%e5%8f%91%e5%b8%83
title: XylFTP客户端（命令行界面）发布
wordpress_id: 29
categories:
- Linux
- Web
---

XylFTP是用java语言编写的ftp客户端，适用于装有java虚拟机的用户，可以完成标准ftp文件传输的基本功能。服务器端正在测试阶段，稍后即将发布，供广大用户使用。XylFTP采用开源软件开发模式，遵循GNU，开放源代码，同安装程序共同发布，欢迎广大开源文化爱好者提出宝贵建议。

在各位老师的耐心指导下，经过小组各位成员的共同努力，XylFTP客户端经过了长期测试和修复，现在已经基本完善和稳定。我们，客户端开发者，宣布正式发布我们的第一个版本供大家使用！

a) 下载：

o XylFTP项目的的主页在：
 [https://sourceforge.net/projects/xylftp](https://sourceforge.net/projects/xylftp)

o XylFTP客户端1.0版本可以在这里下载：
 [http://downloads.sourceforge.net/xylftp/xylftp-client-1.0.tar.gz?modtime=1181322723&big_mirror=0](http://downloads.sourceforge.net/xylftp/xylftp-client-1.0.tar.gz?modtime=1181322723&big_mirror=0)

b) 安装：

o Linux用户安装方法：用命令 tar -xvzf xylftp-client-1.0.tar.gz解压，然后进入文件目录
 xylftp/client/src/，运行"make install"命令即可完成安装。

o Windows用户安装方法：解压安装文件，点击运行目录 xylftp/client/src/中的install.bat
 文件即可完成安装。

c) 卸载：

o Linux用户卸载方法：进入文件目录 xylftp/client/src/，运行"make uninstall"命令即可完成
 软件卸载。
o Windows用户卸载方法：点击运行目录 xylftp/client/src/ 中的uninstall.bat文件即可完成
 软件卸载。

d) 开发：

o XylFTP的CVS在：
 [http://xylftp.cvs.sourceforge.net/xylftp/xylftp/](http://xylftp.cvs.sourceforge.net/xylftp/xylftp/)

o 截止目前，客户端Java代码总量为1800行。参与客户端编写的人员有：

 1.孔建军：实现XylFTPCLI.ShowHelp()，XylFTPCLI.ProcessEcho()等方法，修复一些bug，完成Windows
   上的安装/卸载程序。
 2.周晓炜：完成主程序命令行参数的解析，实现XylFTPMain.main()方法，完善了其它类中的一些方法
 3.王聪：完成整个类框架的编写，实现XylFTPCLI.ParseInput()方法，
   XylFTPException类，XylFTPConnection类， XylTelnetConnection类等，修复一些bug，完成Makefile编写
 4.金明洁：完成javadoc注释和用户文档编写
 5.赵崇日：完成javadoc注释

 感谢各位参与！

欢迎大家测试使用，并把信息及时反馈给我们！
（错误报告请发送至xiyoulinux@googlegroups.com）
