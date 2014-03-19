---
author: amosk
comments: true
date: 2010-06-15 01:14:15+00:00
layout: post
slug: how-to-use-kexec
title: How to use kexec
wordpress_id: 468
categories:
- Linux
---

Tue Jun 15 09:07:36 2010

1. check if current kernel support kexec
# grep KEXEC /boog/config-2.6.34-rc6

2. install kexec tools
1) apt-get / yum install kexec-tools
2) src: http://www.kernel.org/pub/linux/kernel/people/horms/kexec-tools/kexec-tools-2.0.1.tar.gz

3. get command line of new kernel
# cat /boot/grub/menu.lst
title linux-2.6.34-rc7
root (hd0,5)
kernel /boot/vmlinuz-2.6.34-rc7 root=/dev/sda6
initrd /boot/initrd.img-2.6.34-rc7
boot

4. setup parameters
# kexec -l /boot/vmlinuz-2.6.34-rc7 --append="root=/dev/sda6" --initrd=/boot/initrd.img-2.6.34-rc7

5. switch to new kernel
# kexec -e
System will hot-reboot
