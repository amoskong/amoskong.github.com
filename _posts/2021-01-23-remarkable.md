
```
[amos@fedora ~]$ python3 /usr/bin/remarkable
Traceback (most recent call last):
  File "/usr/bin/remarkable", line 65, in <module>
    import remarkable
  File "/usr/lib/python3/dist-packages/remarkable/__init__.py", line 30, in <module>
    from remarkable import RemarkableWindow
  File "/usr/lib/python3/dist-packages/remarkable/RemarkableWindow.py", line 26, in <module>
    gi.require_version('GtkSource', '3.0')
  File "/usr/lib64/python3.9/site-packages/gi/__init__.py", line 129, in require_version
    raise ValueError('Namespace %s not available for version %s' %
ValueError: Namespace GtkSource not available for version 3.0
```


```
[amos@fedora ~]$ remarkable 
Traceback (most recent call last):
  File "/usr/bin/remarkable", line 65, in <module>
    import remarkable
  File "/usr/lib/python3/dist-packages/remarkable/__init__.py", line 30, in <module>
    from remarkable import RemarkableWindow
  File "/usr/lib/python3/dist-packages/remarkable/RemarkableWindow.py", line 27, in <module>
    gi.require_version('WebKit', '3.0')
  File "/usr/lib64/python3.9/site-packages/gi/__init__.py", line 126, in require_version
    raise ValueError('Namespace %s not available' % namespace)
ValueError: Namespace WebKit not available
```

```
sudo dnf install snapd
sudo ln -s /var/lib/snapd/snap /snap
sudo snap install remarkable
```
