
# To print files in a directory

#! /bin/bash

echo "Enter the directory"

read d1

echo "Displaying files in the directory: $d1: "

for i in `ls $d1`
do
	echo $i
done

echo "Thank you"

