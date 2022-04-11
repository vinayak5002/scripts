echo "Menu :"
echo "1. Check voting"
echo "2. Senior citzen"
echo "0. Exit"

read ch

echo "Enter your age"
read age

if (( ch == 1 ));
then 
	if (( age >= 18 ));
	then
		echo "you can vote"
	else
		echo "You can't vote yet"
	fi
else
	if (( age > 75 ));
	then
		echo "You are a senior citizen"
	else
		echo "You are not a senior citizen"
	fi
fi
