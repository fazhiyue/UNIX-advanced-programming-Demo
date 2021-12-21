#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "tlpi_hdr.h"

void *func(void *args)
{
    return 0;
}

int main()
{
    int s;
    pthread_t thread;
    s = pthread_create(&thread, NULL, func, NULL);
    if (s != 0)
        errExitEN(s, "pthread_create");
    pid_t mypid;
    mypid = getpid(); /* Returns process ID of calling process */
    printf("My PID is %ld\n", (long)mypid);
    printf("NO error, bye~\n");
}
