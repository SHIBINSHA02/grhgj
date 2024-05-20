#include<stdio.h>
#include<stdlib.h>
int main()
{
int RQ[100],i,n,head=0,initial;
printf("Enter the numberof request:");
scanf("%d",&n);
printf("Enter the request sequence:");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter inital head position:");
scanf("%d",&initial);

printf("\nThe request sequence is: ");
for(i=0;i<n;i++)
{
head=head+abs(RQ[i]-initial);
printf("%d \t",RQ[i]);
initial=RQ[i];
}
printf("\nHead movements %d",head);
return 0;
}
