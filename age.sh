echo "Enter the current year"
read year
echo "Enter the age"
read age
if(($age<50))
then 
x=50-$age
temp=$(($year+x))
echo "The year at which he/she turns 50 is $temp"
else
x=$age-50
temp=$((year-x))
echo "The year at which he/she turns 50 is $temp"
fi
