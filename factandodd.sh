a=1
while(($a==1))
do
echo "Enter the number:"
read n
echo "1.ODD or EVEN"
echo "2.Factorial"
echo "3.EXIT"
echo "Enter the choice"
read ch
case $ch in
1)
if(($n %2> 0))
then 
echo "Number is odd."
else
echo "Number is even."
fi;;
2)
fact=1
while(($n>0))
do
fact=$((fact*n))
n=$((n-1))
done 
echo "Factorial is $fact.";;
3) 
exit;;
esac 
done
