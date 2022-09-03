#include <iostream>
#include <thread>

using namespace std;

int main() {

    int * a = new int(0);
    int * b = new int(0);
    int * x = new int(0);
    int *y = new int(0);
    thread t2([&]()->void {*b = 1; 
                          *y = *b; 
    });
    thread t1([&]()->void {*a = 1; 
                          *x = *b; 
    });



    t1.join();
    t2.join();

    cout << " a = " << *a << " b = " << *b << " x = " << *x << " y = " << *y << endl;
    delete (a);
    delete (b);
    delete (x);
    delete (y);
    return(0);
}
        
