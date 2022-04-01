#To find the sum of n numbers

#! /bin/bash

s=0

for (( i=1; i<=$1; i++ ))
do
	s=`expr $s + $i`
done

echo "Sum of first $1 numbers is : $s"
