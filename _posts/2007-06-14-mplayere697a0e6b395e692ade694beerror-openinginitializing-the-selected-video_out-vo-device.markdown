---
author: amosk
comments: true
date: 2007-06-14 09:25:23+00:00
layout: post
slug: mplayer%e6%97%a0%e6%b3%95%e6%92%ad%e6%94%beerror-openinginitializing-the-selected-video_out-vo-device
title: Mplayer无法播放:Error opening/initializing the selected video_out (-vo) device
wordpress_id: 39
categories:
- Linux
---

今天把Mplayer升级后居然不能正常播放文件了，提示错误：

Error opening/initializing the selected video_out (-vo) device

最后在网上找到了解决的方法。
打开MPLAYER
右击
选择“preferences"->"Video"选项卡->在"Availabe Drivers"中选择“X11“
点"OK"关闭设置
重启Mplay
