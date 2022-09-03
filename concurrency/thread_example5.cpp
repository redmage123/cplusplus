#include <iostream>
#include <thread>

#define MAX_VALUE 100
using namespace std;


// This program  is illustrating exception safe multithreading code in C++.

void foo(int i) {
    cout << "foo() i = " << i << endl;
}

struct task_struct {

    int & i;
    task_struct (int & ii) : i(ii) {
        cout << " In the task struct constructor.  i = " << i << endl;
    }

    void operator() () {
        for (unsigned j = 0; j < MAX_VALUE; ++j) {
            cout << j << ": foo()\n";
            foo(i);
        }
    }
};


void current_thread_task() {
    cout << "try: current_thread_task() \n";
}


/* Here we're showing an example of exception safe coding.  In this case, 
 * there might be a possibility that the current_thread_task() function 
 * may throw an exception.  If it does so, and we don't catch it, the program
 * will stop execution before we call the join() method. This of course means
 * that we might leak resources. So, in order to defend against this possibility,
 * we wrap the function call in a try/catch and if the function does, in fact,
 * throw an exception, we'll still call the join method which will block the
 * main program until all resources  are released from the child thread.
 * if the try succeeds, then we call join anyway, outside of the try/catch block. 
 * Also, note that we're calling the thread from a function, not from main itself.
*/ 


 
void A_function_creating_a_thread_within() {
    int state = 99;
    task_struct task(state);

    thread t(task);

    try {
        current_thread_task();
    } catch (...) {
        cout << "catch(...)\n";
        t.join();
        throw;
    }
    t.join();
}

int main() {
    A_function_creating_a_thread_within();
    cout << "end of program\n";
    return(0);
}
