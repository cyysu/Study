#!/bin/bash


echo -n "for : "
for ((i = 1; i < 10; i++))
do
	echo -n "$i "
done
echo

echo "i = $i"
echo -n "while : "

i=1
while [ $i -lt 10 ]
do
	echo -n "$i "
	i=$[$i + 1]
done
echo

read -p "please input line : " line
echo ================
i=0
while [ $i -lt $line ]
do
	j=0
	while [ $j -le $i ]
	do
		echo -n "* "
		j=$[$j + 1]
	done
	echo
	i=$[$i + 1]
done
echo ================
