#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void m() {
    counter += 1;
    printf("BB\n");
    printf("Count : %d\n", counter);
} 

void k() {
    counter += 1;
    printf("AA\n");
    printf("Count : %d\n", counter);
    signal(SIGINT, m);
}

main() {
    signal(SIGINT, k);
    for(;;);
}
