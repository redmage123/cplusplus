#include <iostream>

template <class D> 
struct base {
    std::string  foo() {
        static_cast <D *> (this)->foo();
    };
};



struct derived1 : base<derived1> {
    std::string  foo() {
        return  "Foo from derived1";
    };
};

struct derived2 : base<derived2> {
    std::string foo() {
        return  "Foo from derived2";
    };
};


int main() {

    struct derived1 d1;
    struct derived2 d2;


    std::cout << d1.foo() << std::endl;
    std::cout << d2.foo() << std::endl;
}
