#!/bin/bash

read -p 'please input a and b : ' a b

echo "a = $a b = $b"

max=$a

if [ $max -lt $b ]
then
	max=$b
fi

echo "max = $max"
echo ================
if [ $a -ge $b ]
then
	echo "max = $a"
fi

if [ $a -lt $b ]
then
	echo "max = $b"
fi
