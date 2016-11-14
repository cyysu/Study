#!/bin/bash

while [ ! $quit ]
do
	#清屏
	clear
	echo "====>  MEUN  <===="
	echo "=> 1 left up    <="
	echo "=> 2 right up   <="
	echo "=> 3 left down  <="
	echo "=> 4 right down <="
	echo "=> 5 exit       <="
	read -p "please input option : " option

	case $option in
		1)
			#echo "left up"
			for ((i = 0; i < 5; i++))
			do
				for ((j = 0; j <= $i; j++))
				do
					echo -n "* "
				done
				echo
			done
		;;
		2)
			#echo "right up"
			for ((i = 0; i < 5; i++))
			do
				#打印空格
				for ((j = 0; j < 5 - i - 1; j++))
				do
					echo -n "  "
				done
				#打印星号
				for ((j = 0; j <= $i; j++))
				do
					echo -n "* "
				done
				#打印换行
				echo
			done
		;;
		3)
			#echo "left down"
			for ((i = 0; i < 5; i++))
			do
				for ((j = 0; j < 5 - i; j++))
				do
					echo -n "* "
				done
				echo
			done
		;;
		4)
			#echo "right down"
			for ((i = 0; i < 5; i++))
			do
				for ((j = 0; j < i; j++))
				do
					echo -n "  "
				done
				for ((j = 0; j < 5 - i; j++))
				do
					echo -n "* "
				done
				echo
			done
		;;
		5)
			echo "exit"
			quit=1
		;;
		*)
			echo "option error!"
		;;
	esac
	#阻塞的一种方式接受用户输入
	read
done
