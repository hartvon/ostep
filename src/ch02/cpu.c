#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* s = argv[1];
    int n = 5;
    while (n--) {
        sleep(1);
        printf("%s\n", s);
    }

    return 0;
}