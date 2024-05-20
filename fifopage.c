#include <stdio.h>
void main()
 {
   int n,f,fr[20],ref[20],fault=0,miss,fi=0,i,k,h,r;
   printf("Enter the length of reference string:");
   scanf("%d",&n);
   printf("Enter the reference string:");
   for(i=0;i<n;i++)
    scanf("%d",&ref[i]);
   printf("Enter the number of page frames:");
   scanf("%d",&f);
   for(i=0;i<f;i++)
    fr[i]=-1;
   for(i=0;i<n;i++)
    {
      miss=1;
      for(k=0;k<f;k++)
       {
         if(ref[i]==fr[k])
          {
            miss=0;
            break;
          }
       }
      if(miss)
       {
         fr[fi]=ref[i];
         fault++;
         fi=(fi+1)%f;
       }
    }
   printf("\n\nNumber of page fault:%d\n",fault);
   h=n-fault;
   printf("Hit ratio is: %d/%d\n",h,n);
 }
