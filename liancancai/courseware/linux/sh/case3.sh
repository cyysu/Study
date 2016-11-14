#!/bin/bash


#a A => hello
#b B => world

read -p "please input char : " ch

if [ $ch = 'a' -o $ch = 'A' -o $ch = "hello" ]
then
	echo hello
elif [ $ch = 'b' -o $ch = 'B' ]
then
	echo "world"
fi

echo "============="

case $ch in
	'a' | 'A' | "hello")
		echo "case hello"
		;;
	'b' | 'B')
		echo "case world"
		;;
esac
