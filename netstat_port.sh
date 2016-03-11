#!/bin/bash
#Pragram:
#	Using netstat and grep detect WWW,SSH,FTP and mail service.
#History 2016/03/09 zhao Release
PATH=/bin:/sbin:/usr/bin:usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo "Now,I will detect your Linux server's services"
echo -e "The www,ftp,ssh,and mail will be detect!\n"
testing=$(netstat -tuln | grep ":80")
if [ "$testing" != "" ];then
	echo "WWW is running in your system."
fi
testing=$(netstat -tuln | grep ":22")
if [ "$testing" != "" ];then 
	echo "SSH is running in your system."
fi
testing=$(netstat -tuln | grep ":21")
if [ "$testing" != "" ];then 
	echo "FTP is running in your system."
fi
testing=$(netstat -tuln | grep ":25")
if [ "$testing" != "" ];then 
	echo "MAIL is running in your system."
fi
