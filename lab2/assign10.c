#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback_SIGINT() {
    alarm(3);
}

void callback_SIGALRM2() {
    kill(getpid(), SIGTERM);
}

void callback_SIGALRM1() {
    printf("AA\n"); 
    signal(SIGALRM, callback_SIGALRM2); 
    alarm(3);
}

main() {
    signal(SIGALRM, callback_SIGALRM1);
    signal(SIGINT, callback_SIGINT);
    for(;;);
}
