#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void callback() {
    counter += 1;
    if(counter >= 5)
        signal(SIGINT, SIG_DFL);
}

main() {
    signal(SIGINT, callback);
    for(;;);
} 
