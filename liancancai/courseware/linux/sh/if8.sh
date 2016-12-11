#!/bin/bash


read -p "please input class result : " result

if [ $result -gt 100 -o $result -lt 0 ]
then
	echo "class info error!"
	exit
fi

if [ $result -ge 90 ]
then
	echo "优秀"
elif [ $result -ge 70 ]
then
	echo "良好"
elif [ $result -ge 60 ]
then
	echo "及格"
else
	echo "较差"
fi

