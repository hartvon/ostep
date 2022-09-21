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
        pid_t wc = wait(NULL);
        printf("Child (pid:%d) wait return: %d\n", getpid(), wc);
    } else {
        pid_t wc = wait(NULL);
        printf("Parent (pid:%d) wait return: %d\n", getpid(), wc);
    }

    return 0;
}