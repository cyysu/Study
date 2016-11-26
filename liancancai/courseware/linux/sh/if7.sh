#!/bin/bash

clear
echo "===> MEUN <==="
echo "=> 1 蛋炒饭 <="
echo "=> 2 饭炒饭 <="
echo "=> 3 蛋炒蛋 <="
echo "=> 4 exit   <="
read -p "pleasr input option : " option

echo "option = $option"

if [ $option -eq 1 ]
then
	echo "10$"
elif [ $option -eq 2 ]
then
	echo "20$"
elif [ $option -eq 3 ]
then
	echo "30$"
elif [ $option -eq 4 ]
then
	echo "exit"
	exit
else
	echo "option err!"
fi


echo hello
