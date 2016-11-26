#!/bin/bash

read -p "please input number : " num

if [ $num -ge 0 ]
then
	echo "$num 的绝对值是 $num"
else
	echo "$num 的绝对值是 $[$num * -1]"
fi


read -p "please input username : " username

if [ $username = root ]
then
	echo "success!"
else
	echo "false!"
fi
