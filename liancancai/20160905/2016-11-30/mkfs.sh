
#!/bin/sh

#创建一个文件系统并且开启服务   PC端 
FILESYSTEM=/disk/A9/filesystem

cd /disk/A9/

if test  -d  $FILESYSTEM
then
	rm -rf  $FILESYSTEM 
fi

echo   "making    filesystem  starting ..." 
sleep 1
mkdir /disk/A9/filesystem
cd filesystem
cp  ../busybox-1.22.1/_install/* . -r
mkdir  etc dev sys proc opt mnt lib  tmp
mkdir  etc/init.d
sleep 1
mknod  dev/console c  5  1
echo "mount -t ramfs none  /dev"  >> etc/init.d/rcS
echo "mount -t sysfs none  /sys"  >> etc/init.d/rcS 
echo "mount -t proc  none  /proc" >> etc/init.d/rcS 
echo "mount -t tmpfs none  /tmp"  >> etc/init.d/rcS 
echo "/sbin/mdev -s"  >>  etc/init.d/rcS 
echo "::sysinit:/etc/init.d/rcS"  >> etc/inittab
echo "ttySAC0::askfirst:-/bin/sh"  >> etc/inittab 
cp  /opt/FriendlyARM/toolschain/4.5.1/arm-none-linux-gnueabi/lib/*   ./lib/  -r
echo "export PS1=\"[root @ cjy \\W ]# \"" >> etc/profile
cd ..
chmod 777 filesystem  -R

sleep 1
cat  /etc/exports  | grep  "filesystem"
if test $? -ne 0
then
echo "/disk/A9/filesystem   *(rw,sync,no_root_squash)" >> /etc/exports 
fi
sleep 1

service nfs restart
chkconfig nfs on


echo "successfully ... "


