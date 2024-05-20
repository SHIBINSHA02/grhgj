#include<stdio.h>
#include<unistd.h>
void main()
{
	printf("I am A");
	printf("My ID is: %d \n",getpid());
	printf("My parent id : %d \n",getppid());
	printf("\n");
	
	int b=fork();
	if(b==0){
		printf("I am B\n");
		printf("My ID is: %d \n",getpid());
		printf("My parent id : %d \n",getppid());
		
	printf("\n");
	
	int c=fork();
	if(c==0){
		printf("I am C\n");
		printf("My ID is: %d \n",getpid());
		printf("My parent id : %d \n",getppid());
		}
		}

}
