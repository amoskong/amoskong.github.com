---
author: amosk
comments: true
date: 2007-06-13 13:27:50+00:00
layout: post
slug: ftp%e6%96%87%e4%bb%b6%e4%bc%a0%e8%be%93%e6%a8%a1%e5%bc%8fascii-or-binary
title: ftp文件传输模式(ASCII or BINARY)
wordpress_id: 36
categories:
- Web
---

今天添加XylFTP的type命令时，碰到了文件传输模式的问题。

FTP可用多种格式传输文件，通常由系统决定，大多数系统(包括UNIX系统)只有两种模式：文本模式(ASCII)和二进制模式(BINARY)。文本传输器使用ASCII字 符，并由回车键和换行符分开，而二进制不用转换或格式化就可传字符，二进制模式比文本模式更快，并且可以传输所有ASCII值，所以系统管理员一般将 FTP设置成二进制模式。

一般来说：
如果你用错误的模式传输你的图片，你将会无法看到图片，看到的会是乱码。
如果你用错误模式上传CGI脚本，那么就将无法运行你的脚本，会看到类似Server      500      Error的出错信息。
所以你必须使用正确的模式，图片和执行文件必须用BINARY模式，CGI脚本和普通HTML文件用ASCII模式上传.

ASCII和BINARY模式区别：
用HTML      和文本编写的文件必须用ASCII模式上传，用BINARY模式上传会破坏文件，导致文件执行出错。

BINARY模式用来传送可执行文件，压缩文件，和图片文件。
如果你用ASCII模式传，会显示一堆乱码，你必须重新用BINARY模式传。
