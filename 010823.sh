echo "Enter your file name: "
read fname
touch $fname
echo -e "Follow the given functions on file"
echo -e "1. Create a file \n2.Display a file \n3. Insert into file \n4. Delete \n5. Modify a record \n6. Exit">>$fname

ch=0

while [$ch -le '6']
do
	echo -e "ADDRESS BOOK OF EMPLOYEES: \n"
	echo -e "1. Create a file \n2. Display a file \n3. Insert into file \n4. Delete \n5. Modify a record \n6. Exit"
	read ch
	echo -e "1. Name of the Employee \n2. Employee ID \n3. Employee Salary \n4. Employee Designation \n5. Employee Age"
	case $ch in
	1)
		echo "Employee Details are: "
		read n
		for ((i=0; i<$n; i++))
		do
			echo -e "Enter name of the Employee: "
			read ename
			echo -e "Enter Employee_ID of the Employee: "
			read eid
			echo -e "Enter Salary of the Employee: "
			read esalary
			echo -e "Enter designation of the Employee: "
			read edesg
			echo -e "Enter age of the Employee: "
			read eage
			echo -e "$ename \t $eid \t $esalary \t $edesg \t $eage"
		done
		;;
	2)
		cat $fname
		;;
	
	3)
		echo -e "Enter new record"
		echo -e "Enter name of the Employee: "
		read ename
		echo -e "Enter Employee_ID of the Employee: "
		read eid
		echo -e "Enter Salary of the Employee: "
		read esalary
		echo -e "Enter designation of the Employee: "
		read edesg
		echo -e "Enter age of the Employee: "
		read eage
		echo -e "$ename \t $eid \t $esalary \t $edesg \t $eage"
		;;
	
	4)
		echo -e 

	else
		echo "Record not found"
	fi
