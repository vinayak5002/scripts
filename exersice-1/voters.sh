# TO check elegibility of citizen

echo "Enter the age"

read age

if (( $age > 18));
then
	echo "You can vote"
else
	echo "You can't vote yet"
fi
