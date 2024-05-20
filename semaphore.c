#include<stdio.h>
void producer();
void consumer();
int wait(int s)
{
 return --s;
}
int signal(int s)
{
 return ++s;
}
int mutex=1,full=0,x=0;
int empty,n;
void main()
{
 printf("\n--PRODUCER CONSUMER USING SEMAPHORE--\n");

 printf("Enter buffer size:");
 scanf("%d",&empty);
  printf("\n1:Producer\n2:Consumer\n3:Exit:");
 do
 {
  printf("\nEnter Option:");
  scanf("%d",&n);
  switch(n)
  {
   case 1:
   {
   if((mutex==1)&&(empty!=0))
   {
    producer();
   }
   else
   {
    printf("Buffer is FULL!");
   }
   }
   break;
   case 2: 
   {
   if((mutex==1)&&(full!=0))
   {
    consumer();
   }
   else
   {
   printf("Buffer is EMPTY!");
   }
   }
   break;
   case 3 : printf("EXITING....\n"); 
     break;
   default:printf("INVALID CHOICE!\n");
    }
   }while(n != 3);
  }
 
void producer()
{
 mutex=wait(mutex);
 empty=wait(empty);
 x++;
 printf("Producer produced data item %d",x);
 mutex=signal(mutex);
 full=signal(full);
}
void consumer()
{
 mutex=wait(mutex);
 full=wait(full);
 printf("Consumer consumed data item %d",x);
 x--;
 mutex=signal(mutex);
 empty=signal(empty);
}


