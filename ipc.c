#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
void main()
{
int shmid=shmget(65,1024,0666|IPC_CREAT);
char *str1=(char *)shmat(shmid,NULL,0);
printf("Write Data");
gets(str1);
printf("\nData written in memory:%s\n",str1);
shmdt(str1);
}
