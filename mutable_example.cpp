#include <iostream>

using namespace std;

class foo {
    mutable int a = 10;
    public:
    void bar () const {
        a++;
    }
    int  printval() {
        return(a);
    }
};

foo f();
f.bar();
cout << f.printval() << endl;


