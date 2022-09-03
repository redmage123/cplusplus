#include <iostream>

using namespace std;


class Foo {
    public:
        Foo() {
            cout <<"Called the constructor\n";
        }
        ~Foo() {
            cout << "Called the destructor\n";
        }
};

int main(void) {

    Foo *  f = new Foo;
    Foo * f1 = new  Foo;

    delete f;
    delete f1;
}

