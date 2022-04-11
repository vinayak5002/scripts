echo "Enter series of numbers to add"
echo "enter -1 to finish"

sum1=0

read n

while (( n != -1 ))
do
	((sum1= $sum1 + $n ))
	read n
done

echo "Final sum is $sum1"
