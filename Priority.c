#include<stdio.h>
void main()
{
  int pid[10],at[10],bt[10],ct[10],wt[10],tat[10],pr[10],n,i,temp,j;
  double sum_1=0.00,sum_2=0.00;
  printf("\nEnter the number of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter PID:");
    scanf("%d",&pid[i]);
    printf("\nEnter ArrivalTime:");
    scanf("%d",&at[i]);
    printf("\nEnter burst time:");
    scanf("%d",&bt[i]);
    printf("\nEnter priority:");
    scanf("%d",&pr[i]);
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-1-i;j++)
   {
    if(pr[j]>pr[j+1])
    {
      temp = at[j];
      at[j] = at[j+1];
      at[j+1]=temp;
      temp = bt[j];
      bt[j] = bt[j+1];
      bt[j+1]=temp;
      temp = pid[j];
      pid[j] = pid[j+1];
      pid[j+1]=temp;
      temp = pr[j];
      pr[j]=pr[j+1];
      pr[j+1]=temp;
     }
    }
   }
     ct[0]=at[0]+bt[0];
     tat[0]=ct[0]-at[0];
     wt[0]=tat[0]-bt[0];
     for(i=1;i<n;i++)
     {
       ct[i] = ct[i-1] + bt[i];
       tat[i] = ct[i] - at[i];
       wt[i] = tat[i]-bt[i];
     }
     printf("\nThe output is:\n");
     printf("\nPROCESS\tARRIVAL TIME\tCOMPLETIONT IME\tTurn Around Time\t WaitingT ime\tPriority\n");
     for(i=0;i<n;i++)
     {
      printf("\n%d\t%d\t\t%d\t\t%d\t\t %d\t\t%d\n",pid[i],at[i],ct[i],tat[i],wt[i],pr[i]);
     }
     for(i=0;i<n;i++)
     {
       sum_1+=tat[i];
       sum_2+=wt[i];
     }
     printf("\nThe average turn around time is : %lf",sum_1/n);
     printf("\nThe average waiting time is : %lf",sum_2/n);
     printf("\n");
}
