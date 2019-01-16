#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void callback() {
    printf("\nINTERRUPT SIGNAL RECEIVED: Do you want to terminate?\n");
    printf("Enter 0 to terminate and 1 to continue");
    int choice;
    scanf("%d", &choice);
    if(choice == 0) {
	printf("\nSTATUS: Killing process\n");
        kill(getpid(), SIGKILL);
    }

    else if(choice == 1) {
	printf("\nSTATUS: Resuming process\n");
    }

    else {
        printf("\nERROR: Incorrect choice entered. Resuming execution\n");
    }
}

main() {
    signal(SIGINT, callback);
    for(;;);
} 
