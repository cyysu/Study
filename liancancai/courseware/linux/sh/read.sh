#!/bin/bash


#echo -n 'please input number : '
#read -p "please input numbers : " a

#read -s -p 'please input username passwd : ' passwd
###read -t 5 -s -p 'please input username passwd : ' passwd
read -n 6 -p 'please input username passwd : ' passwd

echo "passwd = $passwd"
