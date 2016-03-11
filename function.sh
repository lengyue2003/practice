#!/bin/bash
#Program:
#	Use function to repeat information
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
function printit(){
	echo -n "Your choice is $1"
}
echo "This program will print your select"
case $1 in
"one")
	printit 1
	;;
"two")
	printit 2 
	;;
"three")
	printit 3
	;;
*)
	echo "Usage $0 {one|two|three}"
	;;
esac
