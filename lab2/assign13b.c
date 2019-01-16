#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int childcounter = 0;

void child1();
void child2();

void parent() {
;
}

void child1() {
    printf("%d : X\n", getpid());
    signal(SIGINT, child2);
}

void child2() {
    printf("%d : Y\n", getpid());
    signal(SIGINT, child1);
}

main() {
    printf("Parent ID : %d\n", getpid()); 
    int q = fork();
    if( q!= 0) signal(SIGINT, parent);
    else signal(SIGINT, child1); 
    for(;;);
} 
