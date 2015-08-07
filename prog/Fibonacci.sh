#! /bin/bash

if (($#  <1)) ; then
        echo "Wrong usage!"
        echo "$0 Num"
	echo "Num为输出Fibonacci级数序列的位数"
        exit 1
fi



let "count = $1-2"
a=0
b=1
echo "************Output $1 bases Fibonacci************"

echo "0"
echo "1" 

while test $count -gt 0
do  
let "c=$a +$b"
echo $c
let "a = $b"
let "b = $c"
let "count-=1"
done
