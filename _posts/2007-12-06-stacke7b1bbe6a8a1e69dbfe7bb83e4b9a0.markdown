---
author: amosk
comments: true
date: 2007-12-06 02:42:58+00:00
layout: post
slug: stack%e7%b1%bb%e6%a8%a1%e6%9d%bf%e7%bb%83%e4%b9%a0
title: stack类模板练习
wordpress_id: 156
categories:
- Web
---

以前老听到同学这样抱怨“程序和书上一模一样，为什么会有这么多错误？”今年用的C++已经是我见怪不怪了~~下面是一个stack类模板练习
#include
using namespace std;

template
class Stack {
        private :
                T* date;
                int size;
                int top;
                int IsFull () { return (top >= size )? 1: 0; }
        public:
                Stack (int n ) { date = new T[n];size = n; top =0; }
                ~Stack () {delete date; }
                T pop ();
                void push (T a);
                int IsEmpty () { return (top <= 0 )? 1: 0; }
                void print();
};

template
void Stack::push (T a)
{
        if (IsFull ())
        {
                cout << "Stack overflow\n";
                return;
        }
        *(date + top++) = a;
}
template
inline T Stack::pop ()
{
        if (IsEmpty ())
        {
                cout << "Stack underflow\n";
        }
        return (*(date + --top));
}
template
void Stack::print(){
        while (!IsEmpty()){
                cout << pop() << '\t';
        }
        cout << endl;
}

int main()
{
        Stack  x (5);
        x.push (1);
        x.push (2);
        x.push (3);
        x.push (4);
        x.push (5);

        x.print();

        Stack  y (5);
        y.push ('a');
        y.push ('b');
        y.push ('c');
        y.push ('d');
        y.push ('e');

        y.print();

        return 0;
}
