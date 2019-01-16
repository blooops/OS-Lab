#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback() {
    printf("\nAA\n");
    alarm(3);
}

main() {
    signal(SIGALRM, callback);
    alarm(3); 
    for(;;);
}

