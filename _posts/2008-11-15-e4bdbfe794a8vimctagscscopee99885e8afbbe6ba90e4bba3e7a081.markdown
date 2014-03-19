---
author: amosk
comments: true
date: 2008-11-15 07:07:25+00:00
layout: post
slug: '%e4%bd%bf%e7%94%a8vimctagscscope%e9%98%85%e8%af%bb%e6%ba%90%e4%bb%a3%e7%a0%81'
title: 使用Vim+Ctags+Cscope阅读源代码
wordpress_id: 296
categories:
- Linux
---

_－－孔建军(Kongove.CN)_
2008.11.15


代码阅读工具简介

对于学习Linux内核的人来说，源代码的阅读尤为重要。因为所有设计思想、内部机制都是以代码的形式实现，所有的资料也都是为了更好的诠释代码。那么一个好的阅读工具，能够提高阅读的效率和效果。常见的代码阅读工具有，KScope、Source Navigator、Source Insight、lxr、Cscope等。

* KScope[1]是一款KDE桌面环境下的源代码阅读、浏览工具，自带了编辑功能。比较适合C语言编写的大型项目。KScope底层使用Cscope作为源代码的分析引擎。多数发行版都提供了KScope的安装包。
* "Source Navigator"是红帽子公司的，以GNU GPL发布，可从官方网站[2]下载使用。
* "Source Insight"目前只有Windows平台的，官方网站[3]。需要注册才能使用，或者从网上下载注册机生成注册码。在Linux下通过wine模拟虽然可以方便使用，但它毕竟是Windows平台的东西，并不能很自由的使用。
* lxr(linux cross reference)[4]为程序源代码建立索引数据库,利用perl脚本CGI动态生成包含源码的web页面,你可以用任何一种浏览器查阅。缺点是需要服务器支持，还有速度。
* "Cscope"[5]为终端下的代码阅读工具，资源消耗少，对那些忠于命令行的行操作的人，使用起来更加方便、灵活。这也是这篇文章推荐使用的一个重要原因。也有人把Cscope和Emasc绑定阅读源码。当然工具的选取，也取决于个人习惯。

Vim+Ctags+Cscope

cscope的工作需要vim、ctags的配合，它们都是基于命令行的。在Ubuntu下，用户只需执行“sudo apt-get install cscope cscope-indexer ctags vim”即可完成软件安装。下面只是给出了三种工具的常用方法，更多功能可查看man手册，或者官方文档。
Vim

vim被看作是专门为程序员打造的文本编辑器，其丰富的编辑命令都是常用的简单字符，用户很容易上手。vim可对180多种语言的语法高亮,对C语言自动缩进，真则表达式字符匹配查找，功能强大，并支持多个操作系统平台。关于vim的使用，这里不做讲解。vim中文文档[6]。
Ubuntu系统自带的vim，没有语法加亮功能。上面的安装命令已经更新了vim，在vim 配置文件 ~/.vimrc中 添加一行 "syntax on"，这样在vim中打开的源码就有了语法高亮显示。
vim自带了很多颜色主题，可以直接选取下面一行添加到vim配置文件当中，重新打开vim即可生效。

colorscheme elflord "我使用这个
colorscheme darkblue
colorscheme evening
colorscheme murphy
colorscheme torte
colorscheme desert

Ctags

在源代码根目录下执行 ctags -R 命令用来为程序源代码生成标签文件，其-r选项表示递归操作，同时为子目录也生成标签文件。vim利用生成的标签文件，可以进行相应检索、并在不同的文件C语言元素之间来回切换。

在vim中ctags的简单使用
1) 跳转到指定的函数进入vim后，用 “:tag func_name“ 跳到函数func_name处。使用tag命令时，可以使用TAB键进行匹配查找，继续按TAB键向下切换。
某个函数有多个定义时

:tag
跳到第一个定义处，优先跳转到当前文件
:tnext
跳到第一个
:tfirst
跳到前count个
:[count]tprevious
跳到后count个
:[count]tnext
跳到最后一个
:tlast
你也可以在所有tagname中选择：
:tselect tagname

如果想跳到包含block的标识符:“tag /block” 然后用TAB键来选择。这里'/'就是告诉vim 'block'是一个语句块标签。
2)用“CTRL + ]“快捷键，跳转到光标所在函数标识符的定义处。
3)使用“CTRL + T”退回上层。 如果想在以write_开头的标识符中选择一下， :tselect /^write_ 这里，'^'表示开头，同理，'$'表示末尾。多个同名的标识符
Cscope

运行cscope命令，出现两个面板，上方是一个查找结果的显示面板，下方是一个查找条件指定面板。使用TAB键在两个面板间切换，也可使用上下左右方向件和翻页键在同一面板内贴换位置。选中显示面板的某个项，回车即可进入该文件，这是调用vim打开文件，这时就可以结合ctags使用了。当然也可以直接使用vim打开文件，结合ctags阅读源码。
使用前，必须现使用“cscope-indexer -r”命令递归生成索引信息文件。特殊情况下，还需要用户使用find命令，主动生成索引信息文件，并指定给cscope工具。 cscope提供了如下九种查询方式：

Find this C symbol:
#查找指定的C符号
Find this global definition:
#查找指定的全局定义
Find functions called by this function:
#查找指定函数调用的函数
Find functions calling this function:
#查找调用指定函数的函数
Find this text string:
#查找字符串
Change this text string:
#修改指定字符串
Find this egrep pattern:
#查找匹配字符
Find this file:
#查找指定文件
Find files #including this file:
#指定引用头文件进行查找

在对应某一项中输入查找条件，回车即可进行查询，并将结果显示在显示面板。
应用实例
下面以使用cscope阅读内核源代码为例：

$ wget http://kernel.org/pub/linux/kernel/v2.6/linux-2.6.27.6.tar.bz2
#从Linux内核官网下载内核源代码
$ tar xvfj linux-2.6.27.6.tar.bz2
#解压文件
$ cd linux-2.6.27.6
#进入源代码根目录
$ ctags -R
#递归生成标签文件
$ cscope-indexer -r
#递归生成索引信息文件
$ cscope
#使用cscope阅读源码

对于内核源代码也可以直接使用“make cscope”、“make tags”生成相应的索引信息、标签文件。
标签文件、索引信息文件只需要第一次或者代码发生变动时生成，以后使用直接运行cscope即可。
总结

要达到灵活应用的境界，还必须熟练结合其他工具，如grep、正则表达式等的使用。其中有很多技巧性的东西需要去不断总结、积累。

[1] http://kscope.sourceforge.net/
[2] http://sourcenav.sourceforge.net/
[3] http://www.sourceinsight.com/
[4] http://lxr.linux.no/
[5] http://cscope.sourceforge.net/
[6] http://vcd.gro.clinux.org/
