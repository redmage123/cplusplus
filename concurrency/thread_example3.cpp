#include <iostream>
#include <thread>
#include <mutex> 

using namespace std;

static const int num_threads = 10;
mutex mtx;  // Create a mutex so that we can lock critical code sections

/* Here in the function, we can use a mutex (mutex = MUTual EXclusion ) to 
 * tell the compiler that we only want one thread at a time to access the 
 * critical code section by locking and unlocking it.  The critical section 
 * in question being a cout to stdout. 
*/
void function1(int i) {

    mtx.lock();
    cout << "Launched by thread: " << i << " in function 1" << endl;
    mtx.unlock();
}

/* This is an example of where the threads are all using a shared
 * resource, in this case stdout.  Note that there's no particular
 * order in which output from any thread goes to stdout, which tends
 * to result in munged output.
*/
int main() {

    // Here we create an array of threads which we'll launch. 
    thread t[num_threads];

    // Here we create a thread 't1' and call the structure with
    // the overloaded functor.
    for (int i = 0; i < num_threads; ++i) {
        t[i] = thread(function1,i);
    }
    cout << "Launched from the main\n" << endl;

    // Call the thread.  
    // The main thread gets blocked until the thread is finished, 
    // then we join the main thread again. 
    for (int i = 0; i < num_threads; i++ ) {
        t[i].join();
    }
    cout << "This statement will not execute until all of the other threads have finished" << endl;
    return(0);
}
        
