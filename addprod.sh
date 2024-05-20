add()
{
res=$((x+y))
echo "sum is $res"
}
product()
{
res=$((x*y))
echo "product is $res"
}
echo "enter 2 number"
read x;
read y;
echo "1.add"
echo "2.product"
echo "enter the choice"
read ch
case $ch in
1)add;;
2)product;;
3)exit;;
esac

