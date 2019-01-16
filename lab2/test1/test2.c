#include <stdio.h>
#include <unistd.h>

main() {
    int A, B, C, D;
    A = B = C = D = -1;
    A = getpid();
    fork();
    

    if(getpid() != A) {
	B = getpid();
	fork();
	sleep(1);
    }
    if(getpid() != A && getpid() != B) {
	C = getpid();
	fork();
	sleep(1);
    }
    if(getpid() != A && getpid() != B && getpid() != C) {
	D = getpid();
	sleep(1);
    }

    if(getpid() != A)
	printf("%d  %d\n", getppid(), getpid());
	
    if(getpid() == D)
	printf("%d   %d\n", getpid(), A);
    
    sleep(10);
    
}
