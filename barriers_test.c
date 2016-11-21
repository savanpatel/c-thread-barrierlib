#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>
#include "barrier.h"
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

//int b;






/*void atomic_increment()
{
    pthread_mutex_lock(&lock);
    b++;
    pthread_mutex_unlock(&lock);
}*/

void * barrier_test(void *numthreads)
{
     int r = rand() % 20;
     printf("Sleeping for %d\n", r);
     //sleep(r);
     /*//sleep(r);
     atomic_increment();
     while(b < *(int *)numthreads)
     {
        // sleep(1);
     }*/
     _wait_barrier();
     printf("I am task after barrier\n");

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
