---
layout: post
title: Docker registries mirrors
date: 2020-12-05 19:40
---

Docker Hub is a little bit slow and unstable sometimes in China, it's
always slower than in foreignal Cloud (AWS / GCE). We can use the two
mirrors to speedup the download.

Config file: /etc/docker/daemon.json

```
    {
      "registry-mirrors": [
        "https://4sjn347i.mirror.aliyuncs.com",
        "https://docker.mirrors.ustc.edu.cn"
      ],
      "max-concurrent-downloads": 10,
      "insecure-registries": [],
      "debug": true,
      "experimental": false,
      "features": {
        "buildkit": true
      }
    }
```

BTW, there is a strange problem after linked /var/lib/docker/overlay2 to a directory on another device.
I try to stop docker service before creating the link as suggested by google, but it still has problem.

```
OCI runtime create failed: /var/lib/docker/overlay2/6b43fa390506232a0d0895db436eebaf717d630a05d40b464f24673fdbd273c9/merged is not an absolute path or is a symlink: unknown
```

The solution is moving and creating link for the whole docker directory.

- stop docker service
- mv the whole /var/lib/docker to somewhere (eg: /home/docker/
- create the soft link: ln -s /home/docker /var/lib/docker
- restart docker service
