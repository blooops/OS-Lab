#include<stdio.h>
#include<unistd.h>

main () {
    fork();
    
    fork();

    fork();

    fork();
 
    printf("PID : %d\n", getpid());

    sleep(1);
}
