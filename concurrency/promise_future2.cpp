#include <iostream>
#include <thread>
#include <future>
#include <functional>

using namespace std;

// This is a simple program that demonstrates the concept of promise 

auto p = std::promise<int>();                 

// This is the 'producer' thread that will set a value in the promise
// object.
void producer() {

    p.set_value(1);
}

// This is the 'consumer' thread that will pop values off of the queue.
auto  f = p.get_future();

auto consumer() {
    // The consumer uses the get method  from the future object
    // when the set_value() method from the promise is executed. 
    cout << f.get() << endl;
    }


int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return(0);
}
