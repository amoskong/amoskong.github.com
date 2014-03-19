---
author: amosk
comments: true
date: 2008-03-10 13:32:29+00:00
layout: post
slug: javacontinue%e5%8f%aa%e8%83%bd%e7%94%a8%e4%ba%8e%e8%b7%b3%e5%87%ba%e5%be%aa%e7%8e%af
title: '[Java]continue只能用于跳出循环'
wordpress_id: 198
categories:
- Web
---

// File Name: J_Continue.java
public class J_Continue{
        public static void main(String args[]){
                int i;
                aContinueBlock:
                for (i = 0; i  0)
                                continue aContinueBlock;
                        System.out.println("P 1: i=" + i);
                }
                System.out.println("P 2: i=" + i);
        }
}

这个程序使用了语句块标号，第一眼看感觉可能是个死循环，每次i的值都被初始化为0。
其实程序每次只跳转到for循环内部的最顶部，即从 System.out.println("P 0: i=" + i); 执行。
如果用大括号讲for括起来，甚至再在大括号与for之间加上一句输出语句，都不能正常编译。
如：

                 aContinueBlock:{
                        System.out.println("Hello");
                        for (i = 0; i  0)
                                        continue aContinueBlock;
                                System.out.println("P 1: i=" + i);
                        }
                }

老师的解释是：如果这样就会是continue跟goto语句起相同的作用，使程序不健壮，所以编译器不能通过。

其实问题在于continue只能用于跳出循环的原因，这与 break 不同。
