#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>
#include "barrier.h"



void * barrier_test(void *numthreads)
{
     int r = rand() % 5;
     printf("\nPerforming init task of length %d sec", r);
     sleep(r);

     _wait_barrier();

     printf("\nI am task after barrier");

     return  NULL;
}




int main()
{

    pthread_t tid[20];
    _barrier_init(20);
    int thread_count = 20;
    for(int i =0; i < 20; i++)
    {
        pthread_create(&(tid[i]), NULL, &barrier_test, &thread_count);
    }


    for(int j = 0; j < 20; j++)
    {
        pthread_join(tid[j], NULL);
    }

    return 0;
}
