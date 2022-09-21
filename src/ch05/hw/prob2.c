#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    FILE* f = fopen("./prob2.output", "w+");
    assert(f != NULL);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int ret = fprintf(f, "I am child (pid:%d)\n", getpid());
        assert(ret > 0);
    } else {
        wait(NULL);
        int ret = fprintf(f, "I am parent (pid:%d)\n", getpid());
        assert(ret > 0);
    }

    fclose(f);

    return 0;
}