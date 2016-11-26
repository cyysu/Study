#!/bin/bash

#打印函数
function pri()
{
	for ((k = 0; k <= $1; k++))
	do
		echo -n "$2 "
	done
}

function tri()
{
	#pri 10 "*"
	#pri 5 "="
	#pri 5 " "
	#pri 5 "="
	for ((i = 0; i < 10; i++))
	do
		if [ $i -eq 0 -o $i -eq 1 -o $i -eq 9 ]
		then
			pri $i "*"
		else
			pri 0 "*"
			pri $[$i - 2] " "
			pri 0 "*"
		fi
		#for ((j = 0; j <= i; j++))
		#do
		#	if [ $i -eq 0 -o $i -eq 1 -o $i -eq 9 ]
		#	then
		#		echo -n "* "
		#	else
		#		if [ $j -eq 0 -o $j -eq $i ]
		#		then
		#			echo -n "* "
		#		else
		#			echo -n "  "
		#		fi
		#	fi
		#done
		echo
	done
}

tri
