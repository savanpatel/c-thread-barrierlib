#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>
#include "barrier.h"


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  finish_cond  = PTHREAD_COND_INITIALIZER;
int __barrier = 0;




/*
 * params : number of threads a process is creating.
 * returns : none.
 *
 * Initialize barrier with total number of threads.
 */
void _barrier_init(int n_threads)
{
    __barrier = n_threads;
}



/*
 * params: none.
 * returns: -1 on failure, 0 on success.
 * decrement the count by 1.
 *
 */
int _decrement()
{
    if(pthread_mutex_lock(&lock) != 0)
    {
        perror("Failed to take lock.");
        return -1;
    }


    __barrier--;


    if(pthread_mutex_unlock(&lock) != 0)
    {
        perror("Failed to unlock.");
        return -1;
    }

    return 0;
}




/*
 *  params: none.
 *  returns: int : 0 on sucess, -1 on failure.
 *
 *
 *  wait for other threads to complete.
 */
int _wait_barrier()
{
    if(_decrement() < 0)
    {
        return -1;
    }


    while (__barrier)
    {
        if(pthread_mutex_lock(&lock) != 0)
        {
            perror("\n Error in locking mutex");
            return -1;
        }

        if(pthread_cond_wait(&finish_cond, &lock) != 0)
        {
            perror("\n Error in cond wait.");
            return -1;
        }
    }

    /*
     * last thread will execute this.
     */
    if(0 == __barrier)
    {
        if(pthread_mutex_unlock(&lock) != 0)
        {
            perror("\n Error in locking mutex");
            return -1;
        }
        if(pthread_cond_signal(&finish_cond) != 0)
        {
            perror("\n Eror while signaling.");
            return -1;
        }
    }

    return 0;
}
