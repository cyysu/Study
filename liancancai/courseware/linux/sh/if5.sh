#!/bin/bash

read -p "please input year : " year

echo "year = $year"

if [ $[$year % 400] -eq 0 ]
then
	echo "yes"
else
	if [ $[$year % 4] -eq 0 ]
	then
		if [ $[$year % 100] -ne 0 ]
		then
			echo "yes"
		else
			echo "no"
		fi
	else
		echo "no"
	fi
fi
echo "=========================="

#if [ $[$year % 400] -eq 0 -o  $[$year % 4] -eq 0 -a $[$year % 100] -ne 0 ]
#if [[ $[$year % 400] -eq 0 ||  $[$year % 4] -eq 0 && $[$year % 100] -ne 0 ]]
if [ $[$year % 400] -eq 0 ] || ([ $[$year % 4] -eq 0 ] && [ $[$year % 100] -ne 0 ])
then
	echo "yes"
else
	echo "no"
fi

