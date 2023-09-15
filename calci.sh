ch=0
while [ $ch -lt 5 ] 
do 
	echo "Enter first no."
	read num1
	echo "Enter second no."
	read num2
	echo "Enter your choice from below"
	echo "1. Multiplication"
	echo "2. Addition"
	echo "3. Division"
	echo "4. Substraction"
	read ch
	
	case $ch in
	1)
		num3=$((num1*num2))
		echo $num3
		echo "Press 5 to exit, 0 to continue..."
		read ch
		;;
	2)
		num3=$((num1+num2))
		echo $num3
		echo "Press 5 to exit, 0 to continue..."
		read ch
		;;
	3)
		num3=$((num1/num2))
		echo $num3
		echo "Press 5 to exit, 0 to continue..."
		read ch
		;;
	4)
		num3=$((num1-num2))
		echo $num3
		echo "Press 5 to exit, 0 to continue..."
		read ch
		;;
	*)
	esac
done
echo "Exit Successful!"
	
