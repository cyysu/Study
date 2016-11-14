#!/bin/bash

read -p "please input x and y : " x y

echo "x = $x y = $y"

if [ $x -gt 0 -a $y -gt 0 ]
then
	echo "坐标位于第一象限"
elif [ $x -lt 0 -a $y -gt 0 ]
then
	echo "坐标位于第二象限"
elif [ $x -lt 0 -a $y -lt 0 ]
then
	echo "坐标位于第三象限"
elif [ $x -gt 0 -a $y -lt 0 ]
then
	echo "坐标位于第四象限"
elif [ $x -ne 0 -a $y -eq 0 ]
then
	echo "坐标位于X轴"
elif [ $x -eq 0 -a $y -ne 0 ]
then
	echo "坐标位于Y轴"
elif [ $x -eq 0 -a $y -eq 0 ]
then
	echo "坐标位于原点"
fi
