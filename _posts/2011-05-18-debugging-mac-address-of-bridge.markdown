---
author: amosk
comments: true
date: 2011-05-18 15:39:07+00:00
layout: post
slug: debugging-mac-address-of-bridge
title: Debugging mac address of bridge
wordpress_id: 626
categories:
- kernel
- Linux
---

# strace brctl addbr br0
    ...
    socket(PF_FILE, SOCK_STREAM, 0)         = 3
    ioctl(3, SIOCBRADDBR, 0x7fff0b1240c6)   = 0
    exit_group(0)                           = ?
    
    # ifconfig br0 (got a random address)
    br0       Link encap:Ethernet  HWaddr 5a:34:f1:ba:8f:40 
    
    # strace brctl addif br0 eth0 (no ioctl releated with changing mac)
    ...
    ioctl(4, SIOCGIFINDEX, {ifr_name="eth0", ifr_index=2}) = 0
    close(4)                                = 0
    ioctl(3, SIOCBRADDIF, 0x7fff57c335c0)   = 0
    exit_group(0)                           = ?
    
    # ifconfig br0 (got same addr as eth0)
    br0       Link encap:Ethernet  HWaddr 00:22:68:16:c9:e8  
    
    # grep SIOCBRADDIF -nr net/bridge/
    net/bridge/br_ioctl.c:409:      case SIOCBRADDIF:
    net/bridge/br_ioctl.c:411:              return add_del_if(br, rq->ifr_ifindex, cmd == SIOCBRADDIF);
    
    net/bridge/br_ioctl.c:
    int br_dev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
    {
    ...
            case SIOCBRDELIF:
                    return add_del_if(br, rq->ifr_ifindex, cmd == SIOCBRADDIF);
                               ^
                               |
                               |
    net/bridge/br_ioctl.c      v
    static int add_del_if(struct net_bridge *br, int ifindex, int isadd)
    {
    ...
            if (isadd)
                    ret = br_add_if(br, dev);
                               ^
                               |
                               |
    net/bridge/br_if.c:        v
    int br_add_if(struct net_bridge *br, struct net_device *dev)
    {
    ...
            changed_addr = br_stp_recalculate_bridge_id(br);
                               ^
                               |
                               |
    net/bridge/br_stp_if.c:    v
    bool br_stp_recalculate_bridge_id(struct net_bridge *br)
    {       
            const unsigned char *br_mac_zero =
                            (const unsigned char *)br_mac_zero_aligned;
            const unsigned char *addr = br_mac_zero;
            struct net_bridge_port *p;
            
            /* user has chosen a value so keep it */ <---- we can set a mac to bridge before adding interfaces
            if (br->flags & BR_SET_MAC_ADDR)
                    return false;
            
            list_for_each_entry(p, &br-;>port_list, list) {
                    if (addr == br_mac_zero ||
                        memcmp(p->dev->dev_addr, addr, ETH_ALEN) < 0)
                            addr = p->dev->dev_addr; <---- a 'min' mac address in port_list will be set to bridge
            }
    
    
