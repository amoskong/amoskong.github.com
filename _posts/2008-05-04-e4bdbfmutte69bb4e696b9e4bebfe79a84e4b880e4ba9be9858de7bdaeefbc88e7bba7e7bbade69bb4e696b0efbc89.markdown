---
author: amosk
comments: true
date: 2008-05-04 11:51:37+00:00
layout: post
slug: '%e4%bd%bfmutt%e6%9b%b4%e6%96%b9%e4%be%bf%e7%9a%84%e4%b8%80%e4%ba%9b%e9%85%8d%e7%bd%ae%ef%bc%88%e7%bb%a7%e7%bb%ad%e6%9b%b4%e6%96%b0%ef%bc%89'
title: 使mutt更方便的一些配置（继续更新）
wordpress_id: 229
categories:
- Linux
---

![](http://wiki.mutt.org/mutt.gif)1. 定制邮件头部显示字段列表，先忽略所有字段，然后再选中想看到的
/etc/Muttrc
ignore *
unignore  Date From: to cc Subject X-Mailer Organization
hdr_order Date From To cc Subject  X-Mailer  Organization

2. 定制邮件颜色显示，讲重要信息突出显示很有好处
/etc/Muttrc.d/colors.rc
color normal    white black
#color attachment brightyellow black
#color attachment black black
color attachment yellow black
color hdrdefault cyan black
color indicator black cyan
color markers   brightred black
color quoted    green black
color signature cyan black
color status    brightgreen blue
color tilde     blue black
color tree      red black
color header    brightred black ^From:
color header    green black ^To:
#color header   brightcyan black ^Reply-To:
color header    green black ^Cc:
#color header   brightblue black ^Subject:
#color body     brightred black [\-\.+_a-zA-Z0-9]+@[\-\.a-zA-Z0-9]+
#color body     brightyellow black (https?|ftp)://[\-\.,/%~_:?&=\#a-zA-Z0-9]+
color body      yellow black (https?|ftp)://[\-\.,/%~_:?&=\#a-zA-Z0-9]+

3. 解决部分html字符编码问题,这里的 %{charset} 能自动提取邮件的编码
~/.mailcap
text/html ; w3m -T text/html -I %{charset} -dump %s ; nametemplate=%s.html ; copiousoutput

4. Mutt处理 Word doc 附件。(这个我未实验)
(方法1) 一个完美的解决方案了：使用 wvware 把 doc 转成 HTML 嵌入mutt里。

(方法2) 你也可以让mutt调用 wvHtml 在自己的窗口里直接显示转换的 doc 文档。只需要在 ~/.mailcap 文件加入：
application/msword; wvHtml --charset=gb2312 %s - | lynx --dump -stdin;
nametemplate=%s.html; copiousoutput
text/html; lynx --dump %s; nametemplate=%s.html; copiousoutput
并在 ~/.muttrc 加入：
auto_view text/html application/msword

5. 地址薄：
~/muttrc
#这里是把地址薄单独放到一个文件里
source muttrc.a

~/muttrc.a
alias  linus Linus\ Torvalds  <torvalds@linux-foundation.org>
alias konogve Jianjun\ Kong <kongjianjun@gmail.com>

发邮件时，只需按 M 后，输入linus，就会把 “Linus Torvalds  <torvalds@linux-foundation.org>”添到To CC 里。
输入时也可使用Table键自动匹配。

6. 分屏显示邮件
~/muttrc
#设置在分屏阅读邮件时，邮件标题屏所占的行数。
set pager_index_lines=4

更多配置见：[http://www.kreny.com/docs/mutt.htm](http://www.kreny.com/docs/mutt.htm)

mutt 官网： [http://www.mutt.org](http://www.mutt.org)
