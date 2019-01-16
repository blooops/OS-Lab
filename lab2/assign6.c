#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback() {
    kill(getpid(), SIGTERM);
}

main() {
    signal(SIGINT, callback);
    for(;;) printf("Z\n");
}
