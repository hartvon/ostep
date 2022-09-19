#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int* p = malloc(sizeof(int));
    if (p == NULL) {
        exit(1);
    }
    printf("(%d) memery address of p: %08x\n",
           getpid(), (unsigned)p);
    *p = 0;
    int n = 5;
    while (n--) {
        sleep(1);
        *p += 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }

    return 0;
}