#!/bin/bash

#定义并实现函数
hello()
{
	echo "\$1 = $1"
	echo "\$2 = $2"
	echo "hello"
}

function world()
{
	echo "world"
}

function tri()
{
	for ((i = 0; i < $1; i++))
	do
		for ((j = 0; j <= i; j++))
		do
			echo -n "$2 "
		done
		echo
	done
}
#调用函数
hello 123 "this is a bash"
world
tri 10 "#"
#echo "hello"
