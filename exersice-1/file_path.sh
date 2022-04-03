# Check permission and existence of a file

#!/bin/bash/

if [ -e "$1" ];
then
	echo "Passwords are enabled from $1"
	if [ -x "$1" ];
	then
		echo "You have permissions to execute this file"
	else
		echo "You don't have permissions to ececute this file"
	fi
else
	echo "Passwords are not enabled for the file"
fi
