#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int sum = 0;

void callback() {
    printf("\nSum of previously entered numbers : %d\n", sum);
    kill(getpid(), SIGTERM);
}


main() {
    signal(SIGFPE, callback);
    int input;
    for(;;) {
	printf("Input Number:\n");
	scanf("%d", &input);
	int signal_raiser = 1/(input/5);
	printf("Output Number: %d\n", input*2);
	sum += input;
    }
}
