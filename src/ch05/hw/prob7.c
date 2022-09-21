#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("Child (pid:%d)\n", getpid());
    } else {
        wait(NULL);
        printf("Parent (pid:%d)\n", getpid());
    }

    return 0;
}