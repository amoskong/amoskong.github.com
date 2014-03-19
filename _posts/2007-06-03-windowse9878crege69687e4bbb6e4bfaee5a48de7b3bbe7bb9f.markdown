---
author: amosk
comments: true
date: 2007-06-03 11:56:43+00:00
layout: post
slug: windows%e9%87%8creg%e6%96%87%e4%bb%b6%e4%bf%ae%e5%a4%8d%e7%b3%bb%e7%bb%9f
title: windows里reg文件修复系统
wordpress_id: 26
categories:
- Computer
---

    对于windows里显示隐藏文件、 恢复主页、关闭本机共享文件夹，你或许很清楚如何操作，但往往由于中毒带来的后遗症则不易解决。今天清理磁盘发现了去年在网上找到的几个批处理代码，可以很方便快捷的帮我们搞定这写问题，恢复系统功能。

   操作很简单，将相应代码拷贝到记事本里，让后将记事本的文件名后缀txt改为reg，双击运行就可以了。

  下面顺便给贴出了清理系统多余文件的代码，如果你不是经常清理IE缓存和回收站，可能会腾出很大空间来。

（声明：以下代码我都用过很方便，其他人使用此代码引起的一切后果本人不承担任何责任！）

显示隐藏文件: 

Windows Registry Editor Version 5.00

<!-- more -->

    [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL]
    
    "CheckedValue"=dword:00000001

恢复主页 :

    REGEDIT4
    
    [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Internet Explorer\Main]
    "Default_Page_URL"="[http://www.microsoft.com/isapi/redir.dll?prd=ie&pver=6&ar=msnhome](http://www.microsoft.com/isapi/redir.dll?prd=ie&pver=6&ar=msnhome)"
    "Default_Search_URL"="[http://www.microsoft.com/isapi/redir.dll?prd=ie&ar=iesearch](http://www.microsoft.com/isapi/redir.dll?prd=ie&ar=iesearch)"
    "Start Page"="about:blank"
    
    [HKEY_CURRENT_USER\Software\Policies\Microsoft\Internet Explorer\Control Panel]
    "homepage"=dword:00000000
    
    [HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main]
    "Start Page"="about:blank"
    "Local Page"="C:\\WINDOWS\\System32\\blank.htm"
    "Search Page"="[http://www.microsoft.com/isapi/redir.dll?prd=ie&ar=iesearch](http://www.microsoft.com/isapi/redir.dll?prd=ie&ar=iesearch)"

清理系统多余文件:

    @echo off
    echo It is clearing the rubblish files of system  Wait a minute......
    del /f /s /q %systemdrive%\*.tmp
    del /f /s /q %systemdrive%\*._mp
    del /f /s /q %systemdrive%\*.log
    del /f /s /q %systemdrive%\*.gid
    del /f /s /q %systemdrive%\*.chk
    del /f /s /q %systemdrive%\*.old
    del /f /s /q %systemdrive%\recycled\*.*
    del /f /s /q %windir%\*.bak
    del /f /s /q %windir%\prefetch\*.*
    rd /s /q %windir%\temp & md %windir%\temp
    del /f /q %userprofile%\cookies\*.*
    del /f /q %userprofile%\recent\*.*
    del /f /s /q "%userprofile%\Local Settings\Temporary Internet Files\*.*"
    del /f /s /q "%userprofile%\Local Settings\Temp\*.*"
    del /f /s /q "%userprofile%\recent\*.*"
    echo the End！
    echo. & pause

打开任务管理器:

    REGEDIT4
    
    [HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]
    "disabletaskmgr"=dword:00000000
    
关闭本机共享文件夹:

    REGEDIT4
    
    [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\lanmanserver\parameters]
    "autoshareserver"=dword:00000000
    "autosharewks"=dword:00000000
