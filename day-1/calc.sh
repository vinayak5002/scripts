# Calculator program

#! /bin/bash

echo "Enter 2 numbers"

read n1
read n2

echo "Enter the operations: "
echo "1. addtion"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Divsion"

read op

if (( op == 1 )); then
	echo "The sum of the numbers is $(( $n1 + $n2 ))"
elif (( op == 2 )); then
	echo "The difference of the numbers is $(( $n1 - $n2 ))"
elif (( op == 3 )); then
	echo "The product of the numbers is $(( $n1 \* $n2 ))"
elif (( op == 4 )); then
	echo "The quotient of the numbers is $(( $n1 / $n2 ))"
else
	echo "INVALID REQUEST"
fi
