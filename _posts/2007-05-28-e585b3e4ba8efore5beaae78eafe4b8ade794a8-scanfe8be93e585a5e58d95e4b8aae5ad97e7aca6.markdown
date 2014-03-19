---
author: amosk
comments: true
date: 2007-05-28 08:38:09+00:00
layout: post
slug: '%e5%85%b3%e4%ba%8efor%e5%be%aa%e7%8e%af%e4%b8%ad%e7%94%a8-scanf%e8%be%93%e5%85%a5%e5%8d%95%e4%b8%aa%e5%ad%97%e7%ac%a6'
title: 关于for循环中用 scanf输入单个字符
wordpress_id: 16
categories:
- Web
---

  在创建"图"的时候我发现书上的一个问题,用for循环中用 scanf输入单个字符，很容易将第一次输入的'回车'赋值给下一个字符变量，而出错。我在TC、Win-TC、Gcc都试过了，都存在这个问题。
最后我用getche()代替了用scanf给字符变量赋值,就好了。(Thanks to 林峰)

书上:
for(i=0;ivexnum;i++)
        scanf("%c",&G->vertex[i]);
for(k=0;karcnum;k++){
        scanf("%c,%c,%d",&v1,&v2,&weight);
        i=LocateVex_M(G,v1);
        j=LocateVex_M(G,v2);
        G->arcs[i][j].adj=weight;
}

我修改后的代码:
for(i=0;ivexnum;i++){
        G->vertex[i]=getche();
        printf("\t");
}
for(k=0;karcnum;k++){
        v1=getche();
        printf("\t");
        v2=getche();
        printf("\t");
        scanf("%d",&weight);
        i=LocateVex_M(G,v1);
        j=LocateVex_M(G,v2);
        G->arcs[i][j].adj=weight;
}


   现在慢慢体会到王聪所说的‘laji’book了，前几天发现了几个低级错误，简直怀疑他们贴这些代码前调试过没，还是没必要调试。同样代码运行结果和书上给给出的不一样，而且明显书上的错误着。代码中将两个字符变量名写反，无缘无故多出一个逗号-> ->




          for(vj=0;vj<g.vexnum,;vj++)有点汗~~




  当是买课本时老师一再强调要用高等教育出版社的，连清华也不行，莫非是为了提高我们的查错能里。终于明白了！
