---
author: amosk
comments: true
date: 2008-10-10 09:51:07+00:00
layout: post
slug: python-pinyin-searcher
title: Python Pinyin Searcher
wordpress_id: 283
categories:
- Linux
- Web
---

![python pinyin searcher](/pub/images/pysearcher.png)

一、软件信息
软件名：Python Pinyin Searcher (pysearcher)
软件作者：孔建军（西邮Linux）
软件描述：用Python语言开发的一款，图形界面的汉字拼音查询工具。
软件下载：[http://kongove.whostas.com/down/prog/pysearcher.tar.gz](http://kongove.whostas.com/down/prog/pysearcher.tar.gz)
预期用户：学习汉语拼音的外国朋友。

二、运行环境
GNU/Linux，Windows等支持Python的操作系统
Python2.5以上版本，wxPython图形库

三、功能介绍
1、软件组成：
查询结果显示框、汉字输入窗口、五个按钮(Clear、Paste、Search、Record、Quit)、其他信息框

![](/blog/download/2008/03/Screenshot-10.png)

初始状态下，查询结果显示框输出提示信息“Display The Result Of Search Here...”,汉字输入框显示提示信息”Input or Paste Chinese Words...“，提示信息出于被选状态，焦点处在输入框。由上角显示一手七绝古诗《汉字》及作者信息。
按钮功能描述
Clear：清除输入框信息
Paste：将当前系统剪贴版里的内容粘贴到输入框
Search：对输入框里的信息进行处理，并将结果输出到显示框
Record：将当前显示框内容追加保存到当前目录的record_pinyin.txt文件中
Quit：退出程序

![](/blog/download/2008/03/Screenshot-11.png)

查询结果解释：
“都”can  be read as: dōu / dū
表示汉字”都“可以被读作dōu 或 dū
多音字的多个读音用”/“隔开
结果分色显示，蓝色的为汉字，拼音为红色

![](/blog/download/2008/03/Screenshot-12.png)

使用Paste按钮，粘贴汉字到输入框进行查询

![](/blog/download/2008/03/Screenshot-13.png)

右击输入框/显示框之外的窗口部位，弹出信息窗口。

![](/blog/download/2008/03/Screenshot-14.png)

Windows版本运行效果

四、运行软件
1、下载程序文件，共包含两个文件pysearcher.py和 pinyin.txt；
2、给脚本添加执行权限
$ chmod +x pysearcher.py
3、安装配置Python、wxPython图形库环境
4、在终端下运行程序
$ python pysearcher.py

注:Windows 用户也可以直接下载可执行软件包,解压双击运行里边的 pysearcher.exe 文件

五、其他
后期功能扩展：
1、发音（简单声母、韵母发音表）
2、用鼠标选择任意窗口汉字，弹出小窗口显示结果

任何改进的意见和建议都是受欢迎的！
我的邮箱：kongjianjun@gmail.com
我的主页：[http://amosk.info](http://amosk.info)
