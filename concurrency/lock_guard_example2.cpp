#include <iostream>
using namespace std;

/* In the last example, we see that the program deadlocks because
 * the both method locks the mutex, and then calls mul, which tries
 * to lock it again.  This will deadlock because you can't call the 
 * lock again on a standard mutex.  The solution to this is to use
 * a recursive mutex.
*/ 

struct Complex {

    recursive_mutex mtx;
    int i;
    
    void mul(int x) {
        // Here we are doing a recursive mutex. This won't
        // block even though the both() function already 
        // locks the mutex.
        lock_guard<recursive_mutex> lock(mtx);
        i *= x;
    }

    void div (int x) {
        // Also here as well.
        lock_guard<recursive_mutex> lock(mtx);
        i /= x;
    }

    void both(int x, int y) {
        // Here we do a recursive lock.  This means that other methods
        // in the struct won't block when they try to lock the mutex
        // as well. 
        lock_guard <recursive_mutex> lock (mtx);
        mul(x);
        div(y);
    }
};

int main() {
    Complex cplx;
    cplx.both(5,6);
    return(0);
}




