#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void parent() { printf("%d : X\n", getpid()); }

int childcounter = 0;
void child() {
    childcounter++;
    if(childcounter % 2 == 0) 
        printf("%d : Y\n", getpid());
    else
	printf("%d : Z\n", getpid());
}

main() {
    printf("Parent ID : %d\n", getpid()); 
    int q = fork();
    if( q!= 0) signal(SIGINT, parent);
    else signal(SIGINT, child); 
    for(;;);
} 
