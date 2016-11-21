/*
 *  Barriers aims to synchronize threads to certain point in code execution.
 *  Imagine an implementation of multiplayer game. Each player will have
 *  its own thread of execution and execution times.
 *  But game can not be started unless all the threads have finished their
 *  primary initialization; meaning a thread finished early, must wait for
 *  othres to reach that state.
 *
 *  Such facility is provided in Java using CyclicBarriers.
 *
 * Following is implementation of Barriers in c pthread.
 *
 * A user initializes the thread barrier with passing total number of threads
 * the process is creating.
 *
 * Later, threads can call _wait_barrier(); once it has arrived the state where
 * it must wait for other threads to reach.
 *
 * barrier_test.c provides one such example.
 *
 *
 * @Author : Savan Patel
 *           savanpatel3@gmail.com
 */

#ifndef barrier_h__
#define barrier_h__


/*
 *  params: none.
 *  returns: int : 0 on sucess, -1 on failure.
 *
 *
 *  wait for other threads to complete.
 */
extern int _wait_barrier();


/*
 * params : number of threads a process is creating.
 * returns : none.
 *
 * initializes the barrier.
 */
extern void _barrier_init(int);

#endif
