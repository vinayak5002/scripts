echo "Menu"
echo "1. vote"
echo "2. check senior citizen or not"
echo "Enter choice"

read choice

echo "Enter your age"

read age

if (( $choice == 1 ));
then
	if (( age >= 18 ));
	then
		echo "you can vote"
	else
		echo "You can't vote yet"
	fi
else
	if (( age >= 75 ));
	then
		echo "You are a senior citizen"
	else
		echo "You are not a senior citizen"
	fi
fi
