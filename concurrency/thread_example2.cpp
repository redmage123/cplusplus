#include <iostream>
#include <thread>

using namespace std;

static const int num_threads = 10;

void function1(int i) {
    cout << "Launched by thread: " << i << " in function 1" << endl;
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
    return(0);
}
        
