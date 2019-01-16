#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

clock_t timevar = 0;

void callback() {
    clock_t timeprev = timevar;
    timevar = clock();
    double cpu_time_diff = ((double) (timevar - timeprev)) / CLOCKS_PER_SEC;    
    sleep(1);
    printf("STATUS: Time difference : %lf seconds\n", cpu_time_diff);
}

main () {
    signal(SIGINT, callback);
    for(;;);
}
