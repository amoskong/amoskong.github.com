---
author: amosk
comments: true
date: 2012-12-21 23:35:11+00:00
layout: post
slug: seabios-study-1
title: SeaBIOS study (1)
wordpress_id: 900
categories:
- Computer
- kernel
- Virtualization
---

SeaBIOS [1] 是 x86 结构下的一种 BIOS 的开源实现，可以完成类似 coreboot [2] 初始化硬件后payload的工作，实现一些启动逻辑。

CPU初始化后，放在EIP中执行的第一条指令地址为0xFFFFFFF0，这是intel CPU的一个hack (an inelegant but effective solution to a computing problem)，叫做重置向量(reset_vector)。内存0xFFFFFFF0~0xFFFFFFFF(4G最后边的16bytes)的指令，会将CPU调转到系统BIOS的入口地址0xF0000。系统BIOS被预加载到(0xF0000~0xFFFFF, 960k~1M)。

SeaBIOS/src/ 下只有两个汇编代码：
>>> seabios/src/entryfuncs.S : 这里面是从汇编调用C语言函数的宏定义
>>> seabios/src/romlayout.S :
BIOS 起始函数入口“entry_post”，POST代表 Power-on test-self(加电自检)。 文件头部使用DECLFUNC指令定义了几个函数，有中断处理、 32/16big/16模式转换、resume、PMM(处理器电源管理)、PnP(热插拔)、APM(高级电源管理)、PCI-BIOS、BIOS32、ELF等入口函数。entry_post中，对依次通过一些调转函数或中断，对各类设备进行设置。
“jmp entry_19” 调转到 entry_19 函数，再通过entryfuncs.S 中的宏定义，实际调用src/boot.c中的handle_19()，用于加载启动操作系统。
entry_18/handle_18()则用来处理启动(INT 19)失败。

(引：http://en.wikipedia.org/wiki/BIOS_interrupt_call)
+ 18h Execute Cassette BASIC: True IBM computers contain BASIC in the ROM to be interpreted and executed by this routine in the event of a boot failure (called by the BIOS)
+ 19h After POST this interrupt is used by BIOS to load the operating system.

Qemu[4]解析启动参数(例如：“-boot order=ndc,menu=on,boot-timeout=1000 ..”)，并通过rom中的fw_cfg文件向BIOS传递启动参数，BIOS则通过读取这些文件应用参数。但是SeaBios不只是被Qemu一个项目使用，所以启动参数的默认、启动策略有差异。
关于BIOS启动有一个规范(bios boot specification) [5] www.scs.stanford.edu/nyu/04fa/lab/specsbbs101.pdf，考虑兼容/支持很多硬件，比较复杂，正在读规范中...

Bios为系统ACPI提供DSDT(Differentiated System Description Table，差异系统描述表)，这样ACPI就能通过统一的接口对不同类型的设备进行初始化设置，描述使用的是ASL汇编语言，编译后的16进制文件，可以被标准系统使用。比如热插拔功能，Bios再DSDT表中描述PCI设备(如网卡)，定义电源管理的回调函数，_EJ0方法用于移除一个设备。相应的在操作系统内部，有PCI驱动处理PCI设备的热插拔 (code: linux/drivers/pci/hotplug*)，从固定IO Port探测PCI设备、注册初始化、管理，到最后的销毁。

其他有意思的东西：
SMBios(System Management BIOS): 主板/操作系统厂商显示产品管理信息所需遵循的统一规范
DMI(Desktop Management Interface): 帮助收集电脑系统信息的管理系统

把好几样东西混在了一起，不过基本都是围绕SeaBios的。SeaBios似乎没什么文档，coreboot文档比较齐全。但是有代码和邮件列表在，这就是最好的文档。

[1] [http://www.seabios.org](http://www.seabios.org/)
[2] [http://www.coreboot.org](http://www.coreboot.org/)
[3] [http://en.wikipedia.org/wiki/BIOS_interrupt_call](http://en.wikipedia.org/wiki/BIOS_interrupt_call)
[4] [http://www.qemu.org](http://www.qemu.org)
[5] [http://www.scs.stanford.edu/nyu/04fa/lab/specsbbs101.pdf](http://www.scs.stanford.edu/nyu/04fa/lab/specsbbs101.pdf)
