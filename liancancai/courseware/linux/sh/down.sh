#!/bin/bash

IP=10.1.1.72
SHARE_DIR=/ken

#1 检测网络是否可以连接

if ! ping $IP -c 1 &> /dev/null
then
	echo "no link"
	exit 1
fi

echo "link ok"
umount -l /mnt &> /dev/null
if [ $1 = "down" ]
then
	if showmount -e $IP &> /dev/null
	then
		mount $IP:$SHARE_DIR /mnt &> /dev/null
		/bin/cp /mnt/* /zhangsan -rf
		umount -l /mnt
		echo "down success"
	else
		echo "nfs failed!"
	fi
elif [ $1 = "up" ]
then
	if showmount -e $IP &> /dev/null
	then
		mount $IP:/homework /mnt &> /dev/null
		/bin/cp /zhangsan /mnt -rf
		umount -l /mnt
		echo "up success!"
	else
		echo "nfs failed!"
	fi
else
	echo "format : cmd + [down or up]"
fi


