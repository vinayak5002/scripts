echo "1. Add"
echo "2. Sub"
echo "#. Mul"
echo "4. Div"
echo "Enter you choice"

read choice

echo "Enter 2 operators"

read n1
read n2

if (( $choice == 1 ));
then
	echo "Sum = (( $n1 + $n2 ))"

