#include<stdio.h>
#include<stdlib.h>
void main()
{
    int ioq[20],i,n,j,ihead,temp,scan,tot;
    float seek=0;
    printf("\n---DISK SCHEDULING - SCAN---\n");
    printf("Enter the number of requests : ");
    scanf("%d",&n);
    printf("Enter the initial head position : ");
    scanf("%d",&ihead);
    ioq[0] = ihead;
    ioq[1] = 0;
    n += 2;
    printf("Enter the I/O queue requests : ");
    for(i=2;i<n;i++)
    {
        scanf("%d",&ioq[i]);
    } 
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ioq[j] >ioq[j+1])
            {
                temp = ioq[j];
                ioq[j] = ioq[j+1];
                ioq[j+1] = temp; 
            } 

        }
    }
    ioq[n]=ioq[n-1];
    for(i=0;i<n;i++)
    {
      if(ihead == ioq[i])
        {
            scan = i;
            break; 
        }
    }
    printf("\nOrder of request served : \n\n");
    tot = 0;
    for(i=scan;i>=0;i--)
    {
        tot = ioq[i]-ioq[i-1];
        if(i==0)
        {
            tot=abs(ioq[i]-ioq[scan+1]);
        }
        seek += tot;
        printf("%d\t",ioq[i]);
    }   
    for(i=scan+1;i<n;i++)
    {
        tot = abs(ioq[i+1] - ioq[i]);
        seek += tot;
        printf("%d\t",ioq[i]);
    }
   
    printf("\n\nTotal Seek time : %.2f\n\n",seek);
      
}
