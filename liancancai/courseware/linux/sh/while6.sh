#!/bin/bash

while true
do
	if service nfs status | grep "已停" &> /dev/null
	then
		service nfs restart &> /dev/null
		sleep 5
	fi
done
