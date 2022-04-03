# To print the factorial of a number

#! /bin/bash

fac=1

for (( i=1; i<=$1; i++ ))
do
	fac=`expr $fac \* $i`
done

echo "The factorial of the number is $fac"

