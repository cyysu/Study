#!/bin/bash


for ((i = 1; i < 10; i++))
do
	for ((j = 1; j <= i; j++))
	do
		if [ $[$i * $j]  -ge 10 ]
		then
			echo -n "$j * $i = $[$i * $j] "
		else
			echo -n "$j * $i = $[$i * $j]  "
		fi
	done
	echo
done
