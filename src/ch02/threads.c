#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

volatile int counter = 0;
int loops;

void* woker(void* arg) {
    for (int i = 0; i < loops; ++i) {
        ++counter;
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    assert(argc == 2);
    loops = atoi(argv[1]);
    printf("Initial counter value: %d\n", counter);

    pthread_t p1, p2;
    pthread_create(&p1, NULL, woker, NULL);
    pthread_create(&p2, NULL, woker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final counter value: %d\n", counter);

    return 0;
}