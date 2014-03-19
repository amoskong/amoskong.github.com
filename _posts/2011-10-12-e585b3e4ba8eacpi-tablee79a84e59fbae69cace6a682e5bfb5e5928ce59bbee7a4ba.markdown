---
author: amosk
comments: true
date: 2011-10-12 16:49:42+00:00
layout: post
slug: '%e5%85%b3%e4%ba%8eacpi-table%e7%9a%84%e5%9f%ba%e6%9c%ac%e6%a6%82%e5%bf%b5%e5%92%8c%e5%9b%be%e7%a4%ba'
title: 关于ACPI table的基本概念和图示
wordpress_id: 744
categories:
- Computer
---

[关于ACPI table的基本概念和图示](http://www.cnitblog.com/yuhensong/archive/2009/10/21/62042.html)




ACPI Table是BIOS提供给OSPM的硬件配置数据，包括系统硬件的电源管理和配置管理，ACPI Table有很多表，根据存储的位置，可以分为：

1） RSDP位于F段，用于OSPM搜索ACPI Table，RSDP可以定位其他所有ACPI Table
2） FACS位于ACPI NVS内存，用于系统进行S3保存的恢复指针，内存为NV Store
3） 剩下所有ACPI Table都位于ACPI Reclaim内存，进入OS后，内存可以释放
ACPI Table根据版本又分为1.0B，2.0，3.0，4.0。2.0以后，支持了64-bit的地址空间，因此几个重要的Table会不大一样，比如：RSDP，RSDT，FADT，FACS。简单的列举一下不同版本的ACPI Table：
1） ACPI 1.0B：RSDP1，RSDT，FADT1，FACS1，DSDT，MADT，SSDT，HPET，MCFG等
2） ACPI 3.0 ：RSDP3，RSDT，XSDT，FADT3，FACS3，DSDT，MADT，HPET，MCFG，SSDT等
以系统支持ACPI3.0为例子，说明系统中ACPI table之间的关系如图：


![](http://www.cnitblog.com/images/cnitblog_com/yuhensong/acpitable.JPG)



其中绿色代表在内存F段，蓝色是ACPI Reclaim内存，红色是NV store内存

from:[http://www.cnitblog.com/yuhensong/archive/2009/10/21/62042.html](http://www.cnitblog.com/yuhensong/archive/2009/10/21/62042.html)
