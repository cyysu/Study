#!/bin/bash

IP=10.1.10.172

if ping $IP -c 3 > /dev/null
then
	echo "link ok"
else
	echo "no link"
fi
