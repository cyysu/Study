#!/bin/bash

echo "1 CPU"
echo "2 MEM"
echo "3 disk"
echo "4 exit"

read -p "option : " option

case $option in
	1)
		cat /proc/cpuinfo
		;;
	2)
		cat /proc/meminfo
		;;
	3)
		fdisk -l
		;;
	4)
		echo "exit"
		exit
		;;
	*)
		echo "option error!"
		;;
esac
