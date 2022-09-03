#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/* This code shows an example of a timed mutex.  A timed mutex, like
 * a standard lock, locks a critical section of code, the timed mutex, 
 * however, allows the thread to only block for a specific amount of time
 * and then perform some other actions. In this case, the code attempts
 * to lock the critical section for 100 millisecons (defined by the timeout
 * variable).  If it doesn't work, then it continues on, which, in this
 * case loops again and tries to lock it again. 
*/ 
timed_mutex mtx;
void work() {
    chrono::milliseconds timeout(100);

    while (true) {
        // What happens if the thread already has the mutex locked and 
        // then tries to lock it again? 
        if (mtx.try_lock_for(timeout)) {
            cout << std::this_thread::get_id() << "Doing work with the mutex " << endl;

            chrono::milliseconds sleepDuration(250);
            std::this_thread::sleep_for(sleepDuration);
            mtx.unlock();
            std::this_thread::sleep_for(sleepDuration);
        } else {
            cout << this_thread::get_id() << " Doing work without the mutex " << endl;

            chrono::milliseconds sleepDuration(100);
            std::this_thread::sleep_for(sleepDuration);
        }
    }
}


int main() {

    thread t1(work);
    thread t2(work);

    t1.join();
    t2.join();
    return(0);
}

