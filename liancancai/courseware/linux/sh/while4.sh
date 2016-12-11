#!/bin/bash

#true	表示永远为真
#false  表示永远为假
while true
do
	echo -n "test"
	sleep 1
done

while true
do
	while true
	do
		echo hello
		usleep 100000 
		continue
		#break
		echo world
	done
done
