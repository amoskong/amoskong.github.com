---
layout: post
title: 用Django创建一个简单的动态请求站点
tags : [web, django]
date : 2014-03-18 8:00
---

### 目标

在数梅派上启动一个HTTP服务，通过 GPIO 接口控制继电器 (可以参考 [使用RaspberryPi 的GPIO接口控制LED灯闪烁](http://amosk.info/blog/archives/914) )，从而控制电器的开关。这样可以随时随地控制电源开关。

[下载演示代码](https://github.com/kongove/PowerManagement)

### 首先使用django-admin创建一个project

    # django-admin.py startproject PowerManagement
    # cd PowerManagement/
    # ls
      manage.py  PowerManagement

### 启动服务

    # python manage.py runserver example.com:80
    # w3m http://example.com/

### 这时候访问网站展示的是一个默认的欢迎页面
下面我们来添加一个自己的首页

###### 创建templates目录，并添加到settings.py

    +++ b/PowerManagement/settings.py
    @@ -26,6 +26,10 @@ TEMPLATE_DEBUG = True
     
     ALLOWED_HOSTS = []
     
    +TEMPLATE_DIRS = (
    +    './templates',
    +)
    +
    
###### 更新URL响应方法

    +++ b/PowerManagement/urls.py
    @@ -9,4 +9,5 @@ urlpatterns = patterns('',
         # url(r'^blog/', include('blog.urls')),
     
         url(r'^admin/', include(admin.site.urls)),
    +    url(r'^$', 'PowerManagement.views.home', name='home'),
     )
    
###### 在views.py中实现响应方法，home.html需要在./templates目录添加

    +++ b/PowerManagement/views.py
    @@ -0,0 +1,4 @@
    +from django.shortcuts import render_to_response
    +
    +def home(request):
    +    return render_to_response('home.html')

### 添加新的model (Switch)

    # python manage.py startapp Switch
    # ls Switch/
      admin.py  __init__.py  models.py  tests.py  views.py

###### 添加 子url解析文件

    # vim ./Switch/urls.py
    from django.conf.urls import patterns, include, url
    
    from django.contrib import admin
    admin.autodiscover()
    
    urlpatterns = patterns('',
        url(r'^getstate$', 'Switch.views.getstate', name='getstate'),
        url(r'^setstate$', 'Switch.views.setstate', name='setstate'),
    )

###### 把子url解析文件include到主urls.py

    +++ b/PowerManagement/urls.py
    @@ -10,4 +10,5 @@ urlpatterns = patterns('',
     
         url(r'^admin/', include(admin.site.urls)),
         url(r'^$', 'PowerManagement.views.home', name='home'),
    +    url(r'^switch/', include('Switch.urls')),
     )

###### 创建 Switch 类，其包含一个state 的属性

    +++ b/Switch/models.py
    @@ -1,3 +1,6 @@
     from django.db import models
     
    +
    +class Switch(models.Model):
    +    state = models.IntegerField(default=0)

###### 实现getstate/setstate方法

    +++ b/Switch/views.py
    @@ -1,3 +1,25 @@
     from django.shortcuts import render
    +from django.shortcuts import render_to_response
    +from django.http import HttpResponse
    +from Switch.models import Switch
     
     # Create your views here.
    +
    +def getobj():
    +    try:
    +        s = Switch.objects.get()
    +    except Exception:
    +        s = Switch()
    +        s.save()
    +    return s
    +
    +def getstate(request):
    +    s = getobj()
    +    return HttpResponse('Switch state is (%d)' % s.state)
    +
    +def setstate(request):
    +    s = getobj()
    +    if request.GET.get('state', -1) > 0:
    +        s.state = int(request.GET.get('state'))
    +        s.save()
    +    return HttpResponse('Set switch state to (%d)' % s.state)

### 然后把新的 model 更新到 INSTALLED_APPS，并同步数据库

    +++ b/PowerManagement/settings.py
    @@ -40,6 +40,7 @@ INSTALLED_APPS = (
         'django.contrib.sessions',
         'django.contrib.messages',
         'django.contrib.staticfiles',
    +    'Switch',
     )

    # python manage.py syncdb

### 启动服务

    # python manage.py runserver example.com:8000

### 访问

    # w3m http://example.com/switch/getstate

    Switch state is (4)

    # w3m http://example.com/switch/setstate?state=2

    Set switch state to (2)

