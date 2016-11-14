#!/bin/bash


read -p "please input line : " line

i=0
while [ $i -lt $line ]
do
	j=0
	while [ $j -le $i ]
	do
		if [ $i -eq 0 -o $i -eq 1 -o $i -eq $[$line - 1] ]
		then
			echo -n "* "
		else
			if [ $j -eq 0 -o $j -eq $i ]
			then
				echo -n "* "
			else
				echo -n "  "
			fi
		fi
		j=$[$j + 1]
	done
	echo
	i=$[$i + 1]
done
echo =========================
i=1
while [ $i -le $line ]
do
	j=1
	while [ $j -le $i ]
	do
		if [ $j -eq 1 -o $j -eq $i -o $i -eq $line ]
		then
			echo -n "* "
		else
			echo -n "  "
		fi
		j=$[$j + 1]
	done
	echo
	i=$[$i + 1]
done















