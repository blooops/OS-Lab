#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback() {
    kill(getpid(), SIGTERM);
}

main() {
    signal(SIGALRM, callback);
    alarm(1);
    for(;;) printf("A");
}
