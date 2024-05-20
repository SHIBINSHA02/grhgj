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
    int i,j,n,pid[10],at[10],bt[10],ct[10],wt[10],tat[10],count,tsum=0,wsum=0,start,t;
    int time = 0,over = 0;
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
          swap(pid[j],pid[j+1]);
        }
      }
    }
    

    printf("\nPID\t\tAT\t\tBT\t\tCT\t\tWT\t\tTAT\t\t\n");
    over = 0,time = 0;
    while(over < n)
    {
       count = 0;
       for(i=over;i<n;i++)
       {
          if(at[i] <= time)
          {
            count++;
          
          }
          else
          {
            break;
          }
        }
    
        if(count > 1)
        {
          for(i=over;i<over+count;i++)
          {
              for(j=i+1;j<over+count;j++)
              {
                if(bt[i]>bt[j])
                {
                    t = pid[i];
                    pid[i]=pid[j];
                    pid[j]=t;
                    //swap pidi and j
                    t = at[i];
                    at[i]=at[j];
                    at[j]=t;
                    //swap at
                    t = bt[i];
                    bt[i]=bt[j];
                    bt[j]=t;
                    //swap bt

                }
              }
            }
        }             
        start = time;
        time =  time + bt[over];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[over],at[over],bt[over],time,(time-at[over])-bt[over],time-at[over]);
        tsum=tsum+(time-at[over]);
        wsum=wsum+((time-at[over])-bt[over]);
        over++;
			}
		awt=wsum/n;
		atat=tsum/n;
		printf("Average Waiting time=%f\n",awt);
		printf("Average turnaround time=%f\n",atat);
}
   
