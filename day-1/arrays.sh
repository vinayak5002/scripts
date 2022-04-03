# Using arrays in shell scripting

#! /bin/bash

# declaring and array:
declare -a arr

#initialising an array:
declare -a sports=(football cricket chess)

echo "Enter 3 items: "

read arr[1]
read arr[2]
read arr[3]

echo ${arr[*]}
#alter:
echo ${sports[@]}

