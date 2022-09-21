#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>

#define _GNU_SOURCE
#if __has_include(<features.h>)
#  include <features.h> // __GNU_LIBRARY__
#endif

int main(int argc, char* argv[])
{
    char *args[] = {"ls", "-l", (char *)NULL};
    char *envp[] = {"PATH=/bin:/usr/bin", NULL};
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // execl("/bin/ls", "ls", "-l", (char*)NULL);
        // execlp("ls", "ls", "-l", (char*)NULL);
        // execle("/bin/ls", "ls", "-l", (char*)NULL, envp);
        // execv("/bin/ls", args);
        // execvp("ls", args);
        execve("/bin/ls", args, envp);
// #ifdef __GNU_LIBRARY__
//         execvpe("ls", args, envp);
// #endif
    } else {
        wait(NULL);
    }

    return 0;
}