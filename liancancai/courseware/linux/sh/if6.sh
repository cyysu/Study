#!/bin/bash


if [ ! 1 ]
then
	echo hello
fi


read -p "please input username : " username
read -p "please input passwd : " passwd

#if [[ $username = root && $passwd -eq 123456 ]]
#if [ $username = root ] && [ $passwd -eq 123456 ]
if [ $username = root -o $passwd -eq 123456 ]
then
	echo "success!"
else
	echo "false!"
fi


