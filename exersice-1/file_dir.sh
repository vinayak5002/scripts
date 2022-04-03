# To check file od directory

if [ -f "$1" ]; 
then
	echo "$1 is a regular file"
elif [ -d "$1" ];
then
	echo "$1 is a directory"
else
	echo "The file of another type"
fi
