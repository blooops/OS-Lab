#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 3;

void callback() {
    counter += 1;
    printf("\nAA\n");
    alarm(counter);
}

main() {
    signal(SIGALRM, callback);
    alarm(3); 
    for(;;);
}

