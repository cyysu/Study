#!/bin/bash


read -p "please input class result : " result

if [ $result -gt 100 -o $result -lt 0 ]
then
	echo "class info error!"
	exit
fi

if [ $result -ge 90 ]
then
	option=1
elif [ $result -ge 70 ]
then
	option=2
elif [ $result -ge 60 ]
then
	option=3
else
	option=4
fi

case $option in
	1)
		echo "优秀"
		;;
	2)
	echo "良好"
		;;
	3)
	echo "及格"
		;;
	4)
	echo "较差"
		;;
	*)
		echo "result error!"
		;;
esac

