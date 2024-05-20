#include<stdio.h>
#include<string.h>
struct Pro
   {
       int P,A,B,C,T,W,f;
   }P[50];
void main()
{   
   int l,f,q[50],n,i;
   int swt=0,stat=0;
   float awt,atat;
   int tq;
   float avgtat,avgwt=0;
   printf("Enter the number of process:");
   scanf("%d",&n);
   printf("\nEnter the PIDs:");
   for(i=0; i<n; i++)
   {
      scanf("%d",&P[i].P);
      q[i]=i;
      l=i;              
   }
   printf("\nEnter the arrival time:");
   for(i=0;i<n;i++)
   {
    scanf("%d",&P[i].A);
   }
   printf("\nEnter the burst time:");
   for(i=0;i<n;i++)
   {
    scanf("%d",&P[i].B);
    P[i].f=P[i].B;
   }
   printf("\nEnter TIME QUANTUM:");
   scanf("%d",&tq);
   int k=0,c=0;
   while(k<=l)   
   {
    int m=q[k];
    if(P[m].f>tq)
    {
        c=c+tq;
        P[m].f=P[m].f-tq;
        P[m].C=c;
        l++;               
        q[l]=m;
    }
    else
    {
        c=c+P[m].f;
        P[m].C=c;
    }
    k++;
   }
    
  for(i=0;i<n;i++)
  {
    P[i].T=P[i].C-P[i].A;
  }
  for(i=0;i<n;i++)
  {
    P[i].W=P[i].T-P[i].B;
  }
  for(i=0;i<n;i++)
  {
    avgtat=avgtat+P[i].T;
  }
  for(i=0;i<n;i++)
  {
     avgwt=avgwt+P[i].W;
  }
    awt=(float)avgwt/n;
    atat=(float)avgtat/n;
    printf("\n---ROUNDROBIN SCHEDULING---\n");
    printf("\nPID\t\tAT\t\tBT\t\tWT\t\tTAT");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",P[i].P,P[i].A,P[i].B,P[i].W,P[i].T);
    }
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",atat);
}
