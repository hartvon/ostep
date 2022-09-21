#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 300;
        printf("x = %d (child pid:%d)\n", x, getpid());
    } else {
        x = 200;
        printf("x = %d (parent pid:%d)\n", x, getpid());
    }

    return 0;
}