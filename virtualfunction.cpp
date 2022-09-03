#include <stdio.h>
class myBase {
    public:
    virtual void bar() {
        printf("Base bar!\n");
    }
    virtual void foo() {
        printf("Base foo!\n");
    }
};


class myDerived : public myBase {
    public:
    void bar() {
        printf("Derived bar!\n");
    }
    void foo() {
        printf("Derived foo!\n");
    }
};


int main() {
    myBase * b = new myDerived;
    b->foo();
//    myDerived d;
//   d.foo();
//   d.bar();
}
