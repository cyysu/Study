#!/bin/bash


read -p "please input filename : " file

if [ -L $file ]
then
	echo "$file 已存在"
else
	echo "$file 不存在"
fi
