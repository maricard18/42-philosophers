

#include "philosophers.h"

void*   test()
{
    printf("1");
    sleep(2);
    printf("2");
    return 0;
}

int main()
{
    pthread_t   t1, t2;

    pthread_create(&t1, NULL, &test, NULL);
    pthread_create(&t2, NULL, &test, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}