#!/bin/sh

for pid in `ps aux | grep "\<$1\>$" | awk '{print $2}'`
do 
	echo $pid
	kill -9 $pid
done
