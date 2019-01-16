#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int n = 1;

void callback() {
   printf("\n%d\n", n);
   n++;
   alarm(1); 
}


main() {
    signal(SIGALRM, callback);
    alarm(1);
    for(;;);
}
