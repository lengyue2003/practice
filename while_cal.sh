#!/bin/bash
#Program:
#	Use for to calculate "1+2+3+4+5+6+..+100"
PATH=/bin:/sbin/:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
s=0
i=0
while [ "$i" != "100" ]
do
	i=$(($i+1))
	s=$(($s+$i))
done
echo "The result of '1+2+3+..+100' is $s"
