#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char character = 'Z';

void callback() {
    if(character == 'Z')
        character = 'Y';	
}

main() {
    signal(SIGINT, callback);
    for(;;) printf("%c\n", character);
}
