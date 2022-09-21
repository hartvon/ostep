#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int pipefd[2];
    int ret = pipe(pipefd);
    assert(ret != -1);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello (pid:%d)\n", getpid());
        close(pipefd[0]);
        write(pipefd[1], "c", 1);
        close(pipefd[1]);
    } else {
        close(pipefd[1]);
        char ch;
        read(pipefd[0], &ch, 1);
        close(pipefd[0]);
        printf("goodbye (pid:%d)\n", getpid());
    }

    return 0;
}