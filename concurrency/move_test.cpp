#include <iostream>
#include <thread>

using namespace std;

struct foo {
    foo() {};
    foo( foo && f_other) {
        this->s =  f_other.s;
        f_other.s = NULL;
    }

    char * s = "Hello World";
};


void worker(foo && f1) {

    cout << f1.s << endl;
}

int main()  {

    struct foo f;
    thread t1 (worker,f&&);
    thread t2 (worker,f&&);

    t1.join();
    t2.join();
}
