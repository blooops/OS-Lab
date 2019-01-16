#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void callback() {
    counter += 1;
    if(counter % 2 == 0)
	printf("QQ\n");
    else printf("PP\n");    
}

main() {
    signal(SIGINT, callback);
    for(;;);
}
