#!/bin/bash
#Program:
#	User input a filename,program will check the flowing:
# 	1.)exist? 2)file/directory? 3.)file permission
#History:
#2016/03/08 zhao First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo -e "Please input a filename,I will check the filename's type and permission.\n"
read -p "Input a filename:" filename
test -z $filename && echo "The filename '$filename' Do Not exist" && exit 0
test -f $filename && filetype="regular file"
test -d $filename && filetype="directory"
test -r $filename && perm="readable"
test -w $filename && perm="$perm writable"
test -x $filename && perm="$perm executable"
echo "the filename:$filename is a $filetype"
echo "And the permission are:$perm"
