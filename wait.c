#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	int c =fork();
	if(c==0){
		for(int i=0;i<=10;i++)
		{
			printf("%d\n",i);
		}
		printf("\n");
	}
	else if(c>0){
		wait(NULL);
		for(int i=11;i<=20;i++){
			printf("%d\n",i);
		}
	}	

}
