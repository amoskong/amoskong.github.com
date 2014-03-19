---
author: amosk
comments: true
date: 2010-08-14 15:57:08+00:00
layout: post
slug: python-debug-methods
title: Python Debug Methods
wordpress_id: 472
categories:
- Life
---

1. print
>>> print "hello"

2. logging module
(setup debug level)
>>> logging.debug()
>>> logging.info()
>>> logging.error()

3. import/reload
>>> import test
>>> test.foo()
(change code)
>>> reload(test)
>>> test.foo()

4. exec
>>> d = {}
>>> exec(file('/tmp/test.py'), d)
>>> d.get('foo')(args='hello')

5. eval
>>> evel('foo(args='hello'), d)

6. python -i
python -i test.py
>>> dir()

7. debug tools
pdb  (the usage is very like gdb: b,c,n,l,r,p)
idle
komodo
windpdb

reference:
http://docs.python.org/library/pdb.html
http://aymanh.com/python-debugging-techniques
http://bbs.chinaunix.net/thread-1257503-1-1.html

BTW, shell debug: http://www.ibm.com/developerworks/cn/linux/l-cn-shell-debug/
