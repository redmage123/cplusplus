#include <iostream>
using namespace std;

/* Here we see how deadlocks can happen in C++ multithreaded
 * applications.  In this the Complex structure declares a variable 
 * mtx of type mutex.  The lock_guard template class locks the mtx
 * for the life of a function.  I.e. only when the
 * lock_guard goes out of scope does the lock get freed.
 */

struct Complex {

    mutex mtx;
    int i;
    
    /* Note that the mutex here is locked until the mul method
     * ends.  Once that's done, the lock is freed.  No need
     * to explicitly do an unlock. 
    */
    void mul(int x) {
        lock_guard<mutex> lock(mtx);
        i *= x;
    }

    void div (int x) {
        // Also here as well.
        lock_guard<mutex> lock(mtx);
        i /= x;
    }

    void both(int x, int y) {
        // And yet, a third time.  Actually, the code says that this
        // statement will be run first.  What happens when we call
        // the mul() method?  
        lock_guard <mutex> lock (mtx);
        mul(x);
        div(y);
    }
};

int main() {
    Complex cplx;
    cplx.both(5,6);
    return(0);
}




