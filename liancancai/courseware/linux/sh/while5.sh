#!/bin/bash

i=0
while [ $i -lt 10 ]
do
	i=$[$i + 1]
	if [ $i -eq 7 ]
	then
		break
	fi
	if [ $i -eq 2 -o $i -eq 5 ]
	then
		continue
	fi
	echo -n "$i "
done
echo
