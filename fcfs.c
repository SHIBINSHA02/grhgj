#include<stdio.h>
#include<unistd.h>
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void main()
{
    int i,j,n,pid[10],at[10],bt[10],ct[10],wt[10],tat[10],count,sum;
	float awt =0,atat;
    printf("Enter the no.of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("PID\n");
        scanf("%d",&pid[i]);
        printf("Enter the arrival time:");
        scanf("%d",&at[i]);
        printf("Enter the burst time:");
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
          if(at[j]>at[j+1])
	  {
            swap(at[j],at[j+1]);
            swap(bt[j],bt[j+1]);
            swap(tat[j],tat[j+1]);
	    swap(pid[j],pid[j+1]);
	  }
        
    else if(at[j] == at[j+1])
    {
        if(pid[j] > pid[j+1])
        {
            swap(at[j],at[j+1]);
            swap(bt[j],bt[j+1]);
            swap(tat[j],tat[j+1]);
            swap(pid[j],pid[j+1]);
        }
    }
   }
  }	
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    atat = tat[0];
    wt[0] = tat[0] - bt[0];
    
    for(i=1;i<n;i++)
    {
        ct[i] = ct[i-1]+bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\n---FCFS SCHEDULING---\n\n");
    printf("PID\t\tAT\t\tCT\t\tTAT\t\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],ct[i],tat[i],wt[i]);
        printf("\n");
    }
    
   for(i=1;i<n;i++)
    {
        ct[i] = ct[i-1]+bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
	
        //printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time is: %f\n",awt/n);
    printf("Average Turn Around Time is: %f\n",atat/n);
   
}
