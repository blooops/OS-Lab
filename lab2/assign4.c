#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int counter = 0;

void callback() {
    counter += 1;
    int i;
    printf("\n");    
    for(i=0; i<counter; i++)
        printf("X");
    printf("\n");    
}


main() {
    signal(SIGINT, callback);
    for(;;);
}
