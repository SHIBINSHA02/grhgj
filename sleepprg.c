#include <stdio.h>
#include <unistd.h>

void main(){
    int c = fork(); // Creating a child process
    
    if(c == 0){ // Child process
        for(int i = 0; i <= 10; i++){
            printf("%d\n", i); // Print numbers 0 to 10
        }
        printf("\n");
    }
    else if(c > 0){ // Parent process
        sleep(2); // Sleep for 2 seconds
        for(int i = 11; i <= 20; i++){
            printf("%d\n", i); // Print numbers 11 to 20
        }
    }
}
