#!/bin/bash

sum=0

for i in $(seq 1 1 100)
do
#	echo -n "$i "
	sum=$[$sum + $i]
done
echo "1 + 2 + 3 + ... + 100 = $sum"


for ((i = 1; i <= 100; i++))
do
	result=$[$result + $i]
done
echo "1 + 2 + 3 + ... + 100 = $result"
