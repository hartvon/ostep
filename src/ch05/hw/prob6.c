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
        pid_t wc = waitpid(-1, NULL, WUNTRACED | WCONTINUED);
        printf("Child (pid:%d) waitpid return: %d\n", getpid(), wc);
    } else {
        int status;
        pid_t wc = waitpid(rc, &status, WUNTRACED | WCONTINUED);
        printf("Parent (pid:%d) waitpid return: %d\n", getpid(), wc);
        printf("if the child terminated normally: %s\n",
           WIFEXITED(status) ? "true" : "false");
    }

    return 0;
}