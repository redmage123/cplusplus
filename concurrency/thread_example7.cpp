#include <iostream>
#include <thread>

#define MAX_VALUE 100
using namespace std;


void foo(int i) {
    cout << "foo() i = " << i << endl;
}

struct task_struct {

    int & i;
    string & str;
  
    task_struct (int & ii,string & s) : i(ii) , str(s) {
        cout << " In the task struct constructor.  i = " << i << endl;
    }

    void operator() () {
        for (unsigned j = 0; j < MAX_VALUE; ++j) {
            cout << j << ": foo()\n";
            foo(i);
        }
    }
};

/* This is our class definition that holds a thread.  Note that we both a constructor, 
 * which simply assigns a thread reference to the thread & t instance variable  in the class.
 * The really interesting bit is in the destructor.
 */

class RAII_thread_example {

    thread & t;
    private:
//        RAII_thread_example(RAII_thread_example & thr); // The copy constructor
//       RAII_thread_example &operator=(RAII_thread_example &thr); // The copy assignment operator

    public:
        RAII_thread_example(thread &th): t(th) {
            cout << "In the RAII_thread_example class constructor\n";
        }

        /* Here the destructor needs to tear down the thread reference by the
         * t instance variable.  It tests whether or not the thread is joinable
         * we need to do this because if the thread has already been joined, 
         * then we can't do it again.  
        */
        ~RAII_thread_example() {
            if (t.joinable()) {
                cout << "if joinable() than t.join()\n";
                t.join();
            }
            cout << "In the class destructor";
        }
};

void current_thread_task() {
    cout << "do something in current_thread_task()\n";
}

/* Here in the function, we create an instance of the RAII_thread_example class. 
 * Note that when current_thread_task() returns, the instance is destroyed first, 
 * then the thread itself is destroyed.  Which means it first calls the destructor
 * for the class, which then joins the thread and waits until it's destroyed, then 
 * returns.
*/
void A_function_creating_a_thread_within() {

    int state=99;
    char * s = "Hello World";
    cout << "Launching a thread" << endl;
    thread &t(task_struct task(int state,char * s));
    cout << "Make an instance of the RAII_thread_example class\n";
    RAII_thread_example raii(t);
    cout << "call current_thread_task()\n";
    current_thread_task();
}

int main() {
    A_function_creating_a_thread_within();
    return(0);
}
