# To print contents of the file using command line arguments

#!/bin/bash

echo "Displaying files in the directory: $1"
echo "\n"

for i in `ls $1`
do
	echo $i
done
