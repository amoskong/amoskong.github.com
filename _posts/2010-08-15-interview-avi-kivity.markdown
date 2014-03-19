---
author: amosk
comments: true
date: 2010-08-15 13:22:40+00:00
layout: post
slug: interview-avi-kivity
title: 'Interview: Avi Kivity'
wordpress_id: 475
categories:
- Life
---

## From:http://kerneltrap.org/node/8088




Submitted by [Jeremy](http://kerneltrap.org/user/1)




on April 23, 2007 - 6:06am








	
  * [2.6.20](http://kerneltrap.org/2.6.20)

	
  * [Avi  Kivity](http://kerneltrap.org/taxonomy/term/352)

	
  * [interview](http://kerneltrap.org/taxonomy/term/394)

	
  * [KernelTrap  interview](http://kerneltrap.org/KernelTrap_interview)

	
  * [kvm](http://kerneltrap.org/kvm)

	
  * [lguest](http://kerneltrap.org/lguest)

	
  * [Linux](http://kerneltrap.org/Linux)

	
  * [qemu](http://kerneltrap.org/taxonomy/term/397)

	
  * [virtual  machine](http://kerneltrap.org/virtual_machine)

	
  * [virtualization](http://kerneltrap.org/virtualization)

	
  * [vmware](http://kerneltrap.org/taxonomy/term/396)

	
  * [Xen](http://kerneltrap.org/Xen)

	
  * [Linux  feature interview](http://kerneltrap.org/taxonomy/term/13)









Avi Kivity is the lead developer and  maintainer of the Kernel-based Virtual Machine project, better known as _kvm_.   The project was started in mid-2006, and has been part of the Linux  kernel since the 2.6.20 release in February of 2007.  kvm is a full  virtualization system for x86-based Linux hosts, allowing users to run  isolated x86 guest operating systems in virtual machines.

In this interview, Avi talks about the current status of the kvm  project, detailing what kvm is, how it works, and how it differs from  other virtualization projects.  He goes on to examine future plans for  improving stability and performance.



* * *

**Background:**
_Jeremy Andrews_: Please share a little about  yourself and your background.

![](http://kerneltrap.org/files/avi_small.jpg)_Avi Kivity_: I'm a software developer living in Israel.  I am 36 years old.  Somewhat surprisingly, I studied aeronautical  engineering, but I've designed very few aircraft, being instead swept  away to the fast-paced field of software development.

I currently work at Qumranet Technologies, a start up company which  develops kvm as well as a still-undisclosed proprietary product.

_JA_: Is the undisclosed product related  to kvm and virtualization?

_Avi Kivity_: Yes, it uses kvm as the lowest layer in the stack.

_JA_: When did you get started with Linux?

_Avi Kivity_: About 1996 or 1997 our sysadmin installed Linux  2.0.something on a disused desktop, to act as a firewall.  Out of  curiosity I telnetted in and learned everything I could about it.  I was  already somewhat familiar with Unix, so it wasn't that strange for me.

Some months later that little box took over a few services from our  big NT server, including our all-important version control services.   Visual SourceSafe decided to eat our files while I was branching them  for an important demo, so I wrote a Perl script to check out the  surviving files from SourceSafe and check them in to CVS. I babysat four  or five workstations which were performing the conversion over the  weekend, regularly restarting the NT server when it died.  That little  Linux box didn't even break up a sweat.

**Kvm:**
_JA_: What is your involvement in the kvm  (Kernel-based Virtual Machine) project?

_Avi Kivity_: I am the lead developer and maintainer of kvm.  I  also did what little design work was necessary (though most of kvm's  design is dictated by the hardware specs).

_JA_: What hardware is necessary to use  kvm, and how prevalent is this hardware?

_Avi Kivity_: kvm currently requires an x86 processor that  supports hardware virtualization.  This means an Intel processor  manufactured in the last two years, or a year-old AMD processor.  I  don't know what the installed base of these processors is, but one thing  is certain - it keeps increasing.

I'm hoping that a port of kvm to powerpc will materialize some day so  that kvm will not be x86-only.

_JA_: How can a person tell if their  hardware supports kvm?

_Avi Kivity_: You can easily tell if your processor supports  hardware extensions by running the command

    
        $ egrep '^flags.*(vmx|svm)' /proc/cpuinfo


If there's  any output at all, your processor supports kvm.  Unfortunately, some  early laptops that support kvm have VT extensions disabled in the BIOS,  so a BIOS upgrade is required.  There is also a comprehensive list on  the Xen site, [http://wiki.xensource.com/xenwiki/HVM_Compatible_Processors](http://wiki.xensource.com/xenwiki/HVM_Compatible_Processors).

_JA_: What other architectures are you  aware of that support hardware virtualization?

_Avi Kivity_: Xen supports ia64 (Itanium) and PowerPC in  addition to x86, so at least these two architectures have the necessary  hardware support.

_JA_: Does Qumranet Technologies have any  intention to port kvm to other architectures?

_Avi Kivity_: No.  These ports are best done by the hardware  vendors who have the necessary expertise.  Of course, we will cooperate  and assist the ports in any way we can.

_JA_: What are the similarities and  differences between Intel's virtualization technology and AMD's  virtualization technology?

_Avi Kivity_: In general, the two technologies are similar.   There are some differences, probably attributable to AMD being second to  the market and thus being able to learn from Intel's experience:



	
  * AMD SVM is generally much simpler to program

	
  * AMD SVM contains support for virtualizing real mode (which is used  in the boot sequence); therefore, AMD hosts have better support for boot  loaders

	
  * AMD SVM allows the guest TLB to coexist with the host TLB, which  improves performance; in contrast, on an Intel host a guest/host switch  flushes the TLB


We will probably see a game of leapfrog being played in this area, as  each vendor will try to increase its attractiveness by adding features  and improving performance.

**Compared to other virtualization projects:**
_JA_: What is kvm, and how does it compare to  other virtualization projects?

_Avi Kivity_: kvm is (now) a full virtualization system for  x86-based Linux hosts.  It allows users to create virtual machines and  run various x86 operating systems as isolated guests, similar to other  virtualization and emulation solutions, for example VMware, Xen, and  Qemu.

To compare kvm to other solutions:



	
  * In many ways, VMware is a groundbreaking technology.  VMware manages  to fully virtualize the notoriously complex x86 architecture using  software techniques only, and to achieve very good performance and  stability.  As a result, VMware is a very large and complex piece of  software.kvm, on the other hand, relies on the new hardware virtualization  technologies that have appeared recently.  As such, it is very small  (about 10,000 lines) and relatively simple.  Another big difference is  that VMware is proprietary while kvm is open source.

	
  * Xen is a fairly large project, providing both paravirtualization and  full virtualization.  It is designed as a standalone kernel, which only  requires Linux to perform I/O.  This makes it rather large, as it has  its own scheduler, memory manager, timer handling, and machine  initialization.kvm, in contrast, uses the standard Linux scheduler, memory  management, and other services.  This allows the kvm developers to  concentrate on virtualization, building on the core kernel instead of  replacing it.

	
  * Qemu is a userspace emulator.  It is a fairly amazing project,  emulating a variety of guest processors on several host processors, with  fairly decent performance.  However, the userspace architecture does  not allow it to approach native speeds without a kernel accelerator.   kvm recognizes the utility of qemu by using it for I/O hardware  emulation.  Although kvm is not tied to any particular userspace, the  qemu code was too good not to use -- so we used it.


_JA_: Why is kvm able to use the standard  Linux scheduler, memory management and other services, while the Xen  project had to write its own?

_Avi Kivity_: Xen started out as a paravirtualization system,  without hardware support, back when 32-bit x86 was the predominant  architecture.  Now, if you want to fit a host kernel, a guest kernel,  and guest userspace into a 4GB address space, you've got to make the  host kernel very small - a microkernel.  The Xen developers chose to fit  the host kernel into the top 64MB of memory.  Since Linux won't fit  into such a small space, they had to write a new kernel.

In contrast, the hardware virtualization support utilized by kvm has  explicit support for switching between a host address space and a guest  address space, making a specialized kernel unnecessary.

_JA_: Is kvm a complete replacement for  Xen, or are there still things that Xen can do that kvm does not and may  never do?

_Avi Kivity_: At this point in time, Xen has some features that  kvm does not: guest SMP support, running without hardware extensions,  more paravirtualized device drivers for example.  However, we expect to  close the gap rapidly; in fact in some areas kvm is ahead of Xen: kvm  can do live migration of fully virtualized guests whereas Xen is still  developing this feature.  Laptop users also appreciate the ability to  suspend-to-disk a machine with several guests running and have it  resume.

It is quite possible that one day kvm will gain the ability to run  without hardware support; Rusty Russell's lguest has shown that it can  be done.

_JA_: What I/O hardware emulation does kvm  require from qemu?

_Avi Kivity_: We use qemu for emulating the motherboard  hardware: the pci bus, memory controller, ROM BIOS, VGA graphics, sound  card, IDE controller, and network interface card.  We also use qemu for  emulating the processor's local APIC.

_JA_: What user interfaces are available  for kvm?

_Avi Kivity_: Qemu provides a fairly simple user interface.   More elaborate user interfaces are works in progress: for example,  Fedora's virt-manager is slated to support kvm in Fedora 7.

_JA_: How long has kvm been under  development?

_Avi Kivity_: kvm development started the first half of 2006.   We got Linux x86_64 to boot about two months into development, and  32-bit Windows about a week later.

The remaining time was spent on adding AMD host support, performance  improvements, and stability and correctness.

_JA_: What sorts of feedback did you get  from kernel developers when you first submitted patches against the  kernel?

_Avi Kivity_: I generally received very positive feedback.  Virtualization is an important topic these days, and kvm addresses it in  the Linux way, as a minimally intrusive driver.

**Future plans:**
_JA_: Is kvm's full functionality merged into  the 2.6.20 kernel, or just some parts of it?

_Avi Kivity_: All of kvm is continuously merged into the kernel.   There's usually some lag between our source repository and Linus'  tree, but until now it was pretty short.  I expect the lag to grow a  little as kvm matures and starts to fit into the Linux development  cycle, however we will keep it as short as possible so users can enjoy  the latest and greatest in virtualization.

_JA_: What future plans do you have for  kvm?

_Avi Kivity_: Besides the usual performance and stability  improvements, I'd like to see paravirtualization support (as started by  Ingo Molnar) become a major feature of kvm.

Initially I felt that kvm and paravirtualization had too little in  common to be merged, however after looking at Rusty Russell's lguest I  was convinced that duplicating all the delicate mmu work was wasted  effort and that the projects should merge.

_JA_: What is lguest, and how is it  related to kvm?

_Avi Kivity_: lguest (born lhype) is the paravirtualized  equivalent of kvm.  Where kvm virtualizes an OS-agnostic hardware  platform, lguest is specifically oriented to virtualize Linux guests.   Because the guest and host cooperate, lguest can potentially be very  fast, though at present it has not yet realized this potential.

_JA_: Can you describe what  paravirtualization is, and what's involved in getting kvm to support  paravirtualization?

_Avi Kivity_: Paravirtualization is a technique that is used to  improve virtualization performance.  By making the guest aware that it  is running on a virtualized platform, the guest and host can cooperate,  using more efficient methods of communication.

One example is using paravirtualized drivers.  Instead of emulating a  real network interface card, we use a software interface designed for  performance.  Preliminary numbers from Ingo Molnar show a > 20X  improvement in bandwidth over the qemu emulated NIC.

_JA_: How stable is kvm at this time?

_Avi Kivity_: I find kvm to be very stable: if it runs your  guest, it won't crash.  There are still issues with guest support (e.g.  some guests won't boot, mostly due to real-mode emulation problems on  Intel hosts), and, rarely, some hosts refuse to work with kvm.

_JA_: In what ways can kvm's performance  be improved?

_Avi Kivity_: kvm has not yet undergone major performance  tuning.  Some issues that I'd like to address are:



	
  * avoid saving and loading the floating point unit's state on every  guest/host switch, using a technique similar to the kernel's lazy fpu  mode

	
  * use a better page replacement algorithm when evicting shadow page  tables

	
  * when the guest modifies a page table entry, do the corresponding  modification to the shadow page table entry


_JA_: What limitations does kvm impose  upon guest operating systems?

_Avi Kivity_: kvm tries not to impose any limitations on the  guest other than the type of virtual hardware provided.  Right now we  can only virtualize a single processor, which is a fairly significant  limitation.  Bugs in real-mode emulation mean that some guests may not  boot at all.

_JA_: How long before kvm will be able to  virtualize multiple processors?

_Avi Kivity_: As with most open source projects, it is difficult  to give a timeframe.  I'd like to start work on guest SMP when  processors that support nested page tables appear; that allows work on  the core SMP support to be done without regard to the mmu (which is the  most complex code in kvm).  Once that's done, we can add the necessary  locking and cross-cpu TLB management to the mmu and support older  processors.

_JA_: What are some guests that are not  able to boot?

_Avi Kivity_: Typically guests that use a boot splashscreen in  grub fail on Intel hosts; Ubuntu and opensuse are examples.  In  addition, ACPI support is incomplete, so 64-bit Windows does not work  right now.

In some cases, workarounds are available (for example, disabling the  boot splashscreen).

_JA_: What are some examples of bugs that  prevent guests from being able to boot?

_Avi Kivity_: The major cause of problems is the lack of real  mode support in Intel's virtualization extensions.  When an x86  processor starts up, it executes an instruction set and processing  environment that is compatible with the 16-bit 8086 family; this is  called "real mode" to distinguish it from the "protected mode" in which  modern operating systems such as Linux execute.  Real mode is only used  briefly during the boot stage.

As the hardware doesn't support virtualized real mode fully, kvm has  to emulate it.  Unfortunately, our emulator is incomplete and thus there  are some guests that cannot boot.

I am happy to say that this issue is being addressed and we hope to  have it resolved in the near future.

I should also note that this issue does not affect AMD hosts, which  support real mode virtualization in hardware.

**Wrap up:**
_JA_: What other Linux kernel projects have  you worked on, before kvm?

_Avi Kivity_: Most of my previous work was in userspace.  I did  some hacking on Linux asynchronous I/O as part of a larger project a few  years ago.

_JA_: How do you enjoy spending time when  you're not hacking on the Linux kernel?

_Avi Kivity_: I like going to the movies, listening to music,  reading, playing backgammon (online and in person), table tennis (in  person only!).  I've also taken up snowboarding recently.

_JA_: What advice would you offer to  readers who are only begging to get interested in the inner workings of  the Linux Kernel.

_Avi Kivity_: Read lkml!  There is lots of insight to be gained  from the posts there.

Also, pick an area you have a personal interest in and study it.

_JA_: Is there anything else you'd like to  add?

_Avi Kivity_: One of the benefits of working on the Linux kernel  is that you get to work with some very brilliant developers.  It's  quite an enjoyable experience (barring the occasional flame), and I  learned quite a lot from it.  I'd like to thank the kvm user and  developer community for the testing, feedback, and of course, patches.

_JA_: Thank you for your time answering  these questions, and for all your efforts on the kvm project!



* * *

**Related Links:**



	
  * [Qumranet Home Page](http://qumranet.com/) ([http://qumranet.com/](http://qumranet.com/))

	
  * [KVM Wiki](http://kvm.qumranet.com/kvmwiki) ([http://kvm.qumranet.com/kvmwiki](http://kvm.qumranet.com/kvmwiki))



