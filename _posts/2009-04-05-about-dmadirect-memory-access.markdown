---
author: amosk
comments: true
date: 2009-04-05 01:09:11+00:00
layout: post
slug: about-dmadirect-memory-access
title: About DMA(Direct Memory Access)
wordpress_id: 330
categories:
- Linux
---

在PC上都有一个DMAC(直接内存访问控制器)，用于控制RMA和I/O设备之间的数据传送。DMAC需要被CPU激活，才能自行传送数据，数据传送完，DMAC发出一个中请求。一个名为存储器仲裁器的硬件电路用于解决CPU和DMAC并发访问同一存储单元时的冲突。

DMAC常使用在磁盘驱动器等一次传送大量数据的慢速设备。DMAC的设置时间长，少量数据使用CPU效率较高。

除CPU之外的硬件设备驱动数据总线所用的存储器地址，称作总线地址(bus address)。在PC体系结构中，总线地址和物理地址相同，但在Sun的SPARC和HP的Alpha体系结构中，两者不同。内核提供virt_to_bus和bus_to_virt宏转换线性地址和总线地址。

DMA操作中，I/O设备和DMAC直接驱动数据总线，需要把涉及的存储去缓冲区总线地址写入DMAC相应I/O端口，或I/O设备相应端口。

打开设备文件时，就会分配一条IRQ线准备发送DMA传送结束的信号。为了启动DMA操作，设备驱动程序只是在硬件设备的I/O端口写入DMA缓冲区的总线地址、传输方向和传输数据大小；然后驱动程序挂起当前进程。当DMA结束时，硬件设备产生一个中断唤醒设备驱动程序。当设备文件对象被最后一个进程关闭时，其release方法中释放IRQ线。
