#!/bin/bash


read -p "please input filename : " file

if [ -e $file ]
then
	if [ -r $file ]
	then
		mode="r"
	fi

	if [ -w $file ]
	then
		mode=$mode"w"
	fi

	if [ -x $file ]
	then
		mode=$mode"x"
	fi
fi

echo "$file 的权限 $mode"
