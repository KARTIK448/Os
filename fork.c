#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>
 int main(){
    int p;
    p=fork();

    if(p<0){
        printf("error");
        return 1;
        
    }
    else if(p==0){
        printf("this is child process \n");
        
    }
    else
    printf("hello from parent \n");

 }
 

