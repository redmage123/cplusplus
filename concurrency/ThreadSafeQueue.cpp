#include <iostream>
#include <thread>
#include <queue>
#include <mutex>

/* This is an implementation of a thread safe queue.  The collections 
 * given in the C++ Standard Template Library are not thread safe.
 * That is, it is entirely possible for multiple threads pushing
 * and popping on the same STL queue to collide with each other
 * and cause errors and incorrect values to appear. This code implements
 * a queue that is 'thread safe' using locks and conditional variables to 
 * do so. 
*/
using namespace std;

class ThreadSafeQueue {

    private:
        mutex ml;
        queue<int> q;
        condition_variable d_condition;

    public:

/* The push will first acquire the lock, then it will actually 
 * push the data onto the queue.  Note that once the data is pushed,
 * it will issue a notify to the next thread waiting to access the queue
*/
        void push(int data) {
            unique_lock<mutex> lock(ml);
            q.push(data);
            d_condition.notify_one();
        }

/* Here we are trying to pop a value off of the queue.  We acquire the lock,
 * then we wait on the lock until the notify has occurred and the thread
 * wakes up.  Note that there is also a 'predicate' condition on the wait
 * which says that the wait only occurs if the queue isn't empty.
*/
        int pop() {
            unique_lock<mutex> lock (ml);
            d_condition.wait(lock,[this]{return !(this->q.empty()); });
            int res = this->q.front();
            q.pop();
            return(res);
        }

        int size() {
            return q.size();
        }
};

                 
// This is the 'producer' thread that will push values onto the queue.
void producer(int id,ThreadSafeQueue & tsq) {
    for (int i =0;i<100;i++) {
        tsq.push(i);
        cout << "Produced " << id << " produced " << i << endl;
    }
}

// This is the 'consumer' thread that will pop values off of the queue.
void consumer(int id,ThreadSafeQueue & tsq) {
    int value;
    for (int i =0;i<100;i++) {
        value = tsq.pop();
        cout << "Consumer " << id << " consumed " << value << endl;
    }
}


int main() {
    ThreadSafeQueue tq;
    thread t1(producer,0,ref(tq));
    thread t2(producer,1,ref(tq));
    thread t3(consumer,0,ref(tq));
    thread t4(consumer,1,ref(tq));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return(0);
}
