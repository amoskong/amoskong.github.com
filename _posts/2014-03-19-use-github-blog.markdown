---
layout: post
title: 用Github做主页/博客
tags : [blog,github,web]
date : 2014-03-19 8:00
---

Github博客: [http://github.amosk.info](http://github.amosk.info)

听说用github做博客系统很久了，之前只是传了一个简单的首页，没体会到markdown等支持的方便性。

前几天开始用markdown在github编写博客，感觉方便很多。之前wordpress的博客在国外，访问速度慢，再加上Fedora、chrome等自身的bug，在编辑时候非常痛苦，特别是一些换行、缩进，可能是平时使用文档编辑软件太少，还是喜欢TXT模式。

由于有了markdown的支持，所要表达的样式都很灵活方便，复杂的数学公式都能轻松绘制，更不用说简单的HTML文本样式了。还有一个好处就是能在git log里记录所有更改。

性能方面目前没有啥体会，不知到这种无数据库形式的博客，当博文数量很大时，会不会有问题。

另外就是还没有把以前的博文导入进去，可以参考 [http://jekyllrb.com/docs/migrations/](http://jekyllrb.com/docs/migrations/)，我使用的是 [exitwp](https://github.com/thomasf/exitwp), 需要安装依赖:

    # yum install python-beautifulsoup4 python-html5lib PyYAML html2text

也可以使用ruby的[jekyll-import](http://import.jekyllrb.com/docs/wordpress/)

或者更简单的方法就是，保留一个wordpress来保存之前的博文，[blog.amosk.info](http://blog.amosk.info/) 这是在openshift上备份的一个博客。SAE上不能使用通用的wordpress版本，而且经常流量豆不够用。openshift受GFW影响，重建多次才拿到一个可访问的IP，且智能用https访问，于是有做了[Incapsula](Incapsula.com) 的CDN转换，不过免费用户https又不能用 :-(

网站/博客搬家时候经常丢失东西，特别是一些连接和附件，如果用github备份觉得靠谱 :-)

目前还是继续体验，用markdown写完，复制贴到wordpress里。
