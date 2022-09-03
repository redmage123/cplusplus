#include <iostream>
#include <thread>

using namespace std;

// The overloaded functor () operator is going to get put into 
// a thread when running.
struct F {
    void operator () () const {
        cout << "Hello from the thread functor" << endl;
    }
};

int main() {

    // Here we create a thread 't1' and call the structure with
    // the overloaded functor.
    std::thread t1 { F{} };
    cout << "Hello World" << endl;

    // Call the thread.  
    // The main thread gets blocked until the thread is finished, 
    // then we join the main thread again. 
//    t1.join();
}
        
