---
author: amosk
comments: true
date: 2010-08-15 13:52:43+00:00
layout: post
slug: interview-avi-kivity-2
title: 'Interview: Avi Kivity (2)'
wordpress_id: 478
categories:
- Life
---

### From:http://www.douban.com/note/67747569/


Compared to other virtualization projects:

JA: What is kvm, and how does it compare to other virtualization projects?

Avi Kivity: kvm is (now) a full virtualization system for x86-based Linux hosts. It allows users to create virtual machines and run various x86 operating systems as isolated guests, similar to other virtualization and emulation solutions, for example VMware, Xen, and Qemu.

To compare kvm to other solutions:

In many ways, VMware is a groundbreaking technology. VMware manages to fully virtualize the notoriously complex x86 architecture using software techniques only, and to achieve very good performance and stability. As a result, VMware is a very large and complex piece of software.

kvm, on the other hand, relies on the new hardware virtualization technologies that have appeared recently. As such, it is very small (about 10,000 lines) and relatively simple. Another big difference is that VMware is proprietary while kvm is open source.

Xen is a fairly large project, providing both paravirtualization and full virtualization. It is designed as a standalone kernel, which only requires Linux to perform I/O. This makes it rather large, as it has its own scheduler, memory manager, timer handling, and machine initialization.

kvm, in contrast, uses the standard Linux scheduler, memory management, and other services. This allows the kvm developers to concentrate on virtualization, building on the core kernel instead of replacing it.

Qemu is a userspace emulator. It is a fairly amazing project, emulating a variety of guest processors on several host processors, with fairly decent performance. However, the userspace architecture does not allow it to approach native speeds without a kernel accelerator. kvm recognizes the utility of qemu by using it for I/O hardware emulation. Although kvm is not tied to any particular userspace, the qemu code was too good not to use -- so we used it.

JA: Why is kvm able to use the standard Linux scheduler, memory management and other services, while the Xen project had to write its own?

Avi Kivity: Xen started out as a paravirtualization system, without hardware support, back when 32-bit x86 was the predominant architecture. Now, if you want to fit a host kernel, a guest kernel, and guest userspace into a 4GB address space, you've got to make the host kernel very small - a microkernel. The Xen developers chose to fit the host kernel into the top 64MB of memory. Since Linux won't fit into such a small space, they had to write a new kernel.

In contrast, the hardware virtualization support utilized by kvm has explicit support for switching between a host address space and a guest address space, making a specialized kernel unnecessary.

<!-- more -->

JA: Is kvm a complete replacement for Xen, or are there still things that Xen can do that kvm does not and may never do?

Avi Kivity: At this point in time, Xen has some features that kvm does not: guest SMP support, running without hardware extensions, more paravirtualized device drivers for example. However, we expect to close the gap rapidly; in fact in some areas kvm is ahead of Xen: kvm can do live migration of fully virtualized guests whereas Xen is still developing this feature. Laptop users also appreciate the ability to suspend-to-disk a machine with several guests running and have it resume.

It is quite possible that one day kvm will gain the ability to run without hardware support; Rusty Russell's lguest has shown that it can be done.

JA: What I/O hardware emulation does kvm require from qemu?

Avi Kivity: We use qemu for emulating the motherboard hardware: the pci bus, memory controller, ROM BIOS, VGA graphics, sound card, IDE controller, and network interface card. We also use qemu for emulating the processor's local APIC.

JA: What user interfaces are available for kvm?

Avi Kivity: Qemu provides a fairly simple user interface. More elaborate user interfaces are works in progress: for example, Fedora's virt-manager is slated to support kvm in Fedora 7.

JA: How long has kvm been under development?

Avi Kivity: kvm development started the first half of 2006. We got Linux x86_64 to boot about two months into development, and 32-bit Windows about a week later.

The remaining time was spent on adding AMD host support, performance improvements, and stability and correctness.

JA: What sorts of feedback did you get from kernel developers when you first submitted patches against the kernel?

Avi Kivity: I generally received very positive feedback. Virtualization is an important topic these days, and kvm addresses it in the Linux way, as a minimally intrusive driver
