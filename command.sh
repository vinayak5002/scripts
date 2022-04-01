#To print the command line arguments

#! /bin/bash

echo "Number of command line arguments : $#"
echo "The command line arguments are: $*"

echo "Number of lines in the file $1: "
ls -l $1| wc -l

echo "Files in a directory: #2"
ls -l $2 | grep "^-" | wc -l

echo "Thank you"


