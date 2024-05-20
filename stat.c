#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
void  main(){
	struct stat buff;
	stat("/home/user/Desktop/S4CS51",&buff);
	printf("\n size of file is %ld",buff.st_size);
	printf("\n Type of file is %d",buff.st_mode);
	printf("\n no of hard links in %ld",buff.st_nlink);	


}

