#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret == -1) {
        fprintf(stderr, "pipe failed\n");
    }

    pid_t rc[2];
    rc[0] = fork();
    if (rc[0] < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc[0] == 0) {
        close(pipefd[0]);
        if (pipefd[1] != STDOUT_FILENO) {
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
        }
        printf("First child say hello.\n");
    } else {
        rc[1] = fork();
        if (rc[1] < 0) {
            fprintf(stderr, "fork failed");
            exit(1);
        } else if (rc[1] == 0) {
            close(pipefd[1]);
            if (pipefd[0] != STDIN_FILENO) {
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);
            }
            char buf[1024];
            read(STDIN_FILENO, buf, sizeof(buf));
            printf("Second child print: %s\n", buf);
        } else {
            if (waitpid(rc[0], NULL, 0) == -1) {
                fprintf(stderr, "waitpid rc[0] failed\n");
            }
            if (waitpid(rc[1], NULL, 0) == -1) {
                fprintf(stderr, "waitpid rc[1] failed\n");
            }
        }
    }
    return 0;
}