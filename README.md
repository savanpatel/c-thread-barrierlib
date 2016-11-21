# c-thread-barrierlib
pthread barriers implementation as shared library.

## Motivation


CyclicBarrier in Java provides a thread synchronization mechanism where a thread waits for other sibling threads to complete thier task and arrive at a certain execution point. CyclicBarrier is a natural requirement for a concurrent program because it can be used to perform final part of the task once individual tasks  are completed.

For example, a multiplayer game can not begun unless all the player threads have finished with initialization.

barrierlib is a shared library in c providing similar support for the pthreads.

## Code Example/ Usage

Initializing thread barrier in process

```
#include "barrier.h"
..
..
int main()
{
    ..
    ..
    int num_threads = 10;
    _barrier_init(num_threads);
    ..
    ..
    // create 10 threads.
    ..
    return 0;
 }
```


Consider the following function being exevuted by thread
```
  void * thread_run_fn(void *args)
  {
      ...
      ...
      // some task thread is doing.
      _wait_barrier(); // <-- thread will wait here until all other threads have arrived at this point.
      
      ..
      ..
  }
 ```
 
 
 ## Compiling
 ```
 $ #Navigate to folder src/
 $ make
 ```
 To link to your code
  1. Include "barrier.h" in source code.
  2. Compile with:
  ```
   $ gcc -L<path_to_shared_lib> -Wall -o your_code-out -g -pthread your_code.c -lbarrier -Wl,-rpath=<path_to_shared_lib>
   $ # refer to Make file for example.
  ```
 
## Test
 
 
barrier_test.c is a test file.
To run test
```
 $make test
```

## License
---



The MIT License (MIT)

Copyright (c) Savan Patel <savanpatel3@gmail.com> (savanpatel.in)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
