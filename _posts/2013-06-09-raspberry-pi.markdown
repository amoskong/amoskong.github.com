---
author: amosk
comments: true
date: 2013-06-09 03:08:43+00:00
layout: post
slug: raspberry-pi
title: 使用RaspberryPi 的GPIO接口控制LED灯闪烁
wordpress_id: 914
categories:
- Programming
---

数梅派入门设置：[http://my.oschina.net/quanpower/blog/105247](http://my.oschina.net/quanpower/blog/105247)

下面的 Shell 和 C 代码，都是先了通过控制GPIO针的高低电频，闪烁LED灯。可以结合其他程序来做消息提醒。Shell中使用的针号是GPIO的编号，如 GPIO11 对应 11。但C代码中需要传递broadcom编排的ID，GPIO11对应broadcom的 0。

GPIO23->4, GPIO11->14, GPIO24->5, GPIO17->0,....

[![shumei](http://amosk.info/blog/wp-content/uploads/2013/06/shumei.png)](http://)

![电路图](http://img.bianbian.me/blog/201207/ledtest.png)

    
    #!/bin/bash
    # usage: bash led.sh $perid $repeat $pin
    
    function set_led()
    {
        perid=$1
        repeat=$2
        pin=$3
    
        cd /sys/class/gpio/
        echo $pin > export    #将对应pin的操作暴露再sys文件系统下
        echo out > gpio$pin/direction #控制电流走向，这里需要高电频的时候，电流流向接地线，从而LED发光，所以设置为out
    
        for i in `seq $repeat`;do
            echo 1 > gpio$pin/value #设置高电频，点亮LED
            sleep $perid
            echo 0 > gpio$pin/value #设置底电频，关闭LED
            sleep $perid
        done
        echo $pin > unexport
    }
    
    if [ $# -eq 3 ]; then
        set_led $1 $2 $3
    fi




    
    #include <wiringpi.h>
    #include <stdio.h>
    #include <stdlib.h>
    
    /*
     * compile: apt-get install i2c-tools libi2c-dev python-smbus
     *          gcc led.c -o led -lwiringPi
     * usage ./led $perid $repeat $pin
    */
    
    void set_led(int pin, int status)
    {
    	pinMode (pin, OUTPUT); //设置输出模式
    	digitalWrite (pin, status);
    }
    
    void blink(int pin, int perid, int repeat)
    {
    	while (repeat--)
    	{
    		set_led(pin, 1); //设置高电频
    		delay(perid);
    		set_led(pin, 0); //设置底电频
    		delay(perid);
    	}
    }
    
    int main (int argc, char *argv[])
    {
    	int pin_num = 0;
    	int perid = 100;
    	int repeat = 1;
    
    	if (argc > 1)
    		perid = atoi (argv[1]);
    	if (argc > 2)
    		repeat = atoi (argv[2]);
    	if (argc > 3)
    		pin_num = atoi (argv[3]);
    
    	if (-1 == wiringPiSetup())
    	{
    		printf ("Setup wiringPi failed!");
    		return 1;
    	}
    
    	printf ("blink pin(%d) for %d times (perid:%d)\n",
     		pin_num, repeat, perid);
    	blink (pin_num, perid, repeat);
    
    	return 0;
    }
    
