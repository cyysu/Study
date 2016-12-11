#!/bin/bash

i=0
while [ $i -le 100 ]
do
	sum=$[$sum + $i]
	i=$[$i + 2]
#	let i++ ++
#	let i++
done
echo "2 + 4 + 6 + ... + 100 = $sum"
echo =====================
i=1
while [ $i -le 9 ]
do
	j=1
	while [ $j -le $i ]
	do
		echo -n "$j * $i = $[$i * $j]  "
		let j++
	done


	echo
	let i++
done

