#!/bin/bash

#Program:
#    auto mount  teacher's /homework /ken
#    and download courseware,upload homework

#History:
#    2016.09.19    lcc    first relase

IP=10.1.1.172
#IP=172.16.1.60 
KEN=/ken
HOMEWORK=/homework

MNT_KEN=/mnt_ken
MNT_HOMEWORK=/mnt_homework

MY_KEN=/Study/liancancai/courseware
MY_HOMEWORK=/Study/liancancai/63_连灿材

umount -l $MNT_KEN
umount -l $MNT_HOMEWORK

# test ping 
if ping $IP -c 3   &> /dev/null; then
    echo "ping OK"
else
    echo "$IP fail"
	exit 0
fi

# test nfs
if showmount -e $IP &> /dev/null; then
    echo "nfs OK"
else
    echo "nfs is not work"
fi
 
# mount 
if mount $IP:$KEN $MNT_KEN &> /dev/null; then
    echo "ken mount OK"
else
    echo "ken mount fail"
fi

if mount $IP:$HOMEWORK $MNT_HOMEWORK &> /dev/null; then
    echo "homework mount OK"
else
    echo "homework mount fail"
fi

# Download
if /bin/cp -r -f $MNT_KEN/*  $MY_KEN ; then
    echo "Download OK"
else
    echo "Download fail"
fi

# Upload
if /bin/cp -r  $MY_HOMEWORK  $MNT_HOMEWORK &> /dev/nul; then
    echo "Upload OK"
else
    echo "Upload fail"
fi


umount -l $MNT_KEN
umount -l $MNT_HOMEWORK





