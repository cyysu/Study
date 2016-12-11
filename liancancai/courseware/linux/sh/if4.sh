#!/bin/bash

read -p "please input username : " username

if [ $username = root ]
then
	read -p "please input passwd : " passwd
	if [ $passwd -eq 123456 ]
	then
		echo "success!"
	else
		echo "passwd false"
	fi
else
	echo "username false!"
fi


