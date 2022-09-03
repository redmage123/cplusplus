#include <iostream>

int foo(int & x) {
    x = 10;
}

int main () {

    int a = 5;
    int & b = a;

    std::cout << "Before passing by reference a = "<<a << std::endl;
    foo(b);
    std::cout << "After passing by reference a = " <<a << std::endl;
}

