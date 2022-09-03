#include <iostream>

using namespace std;

int main() {

    struct test {
        int foo;
        char bar;
    };

    struct test * t = (struct test * ) malloc (sizeof(struct test));
    struct test t1 = struct test;



    t->foo = 5;
    t->bar = 'A';

    t1.foo = 10;
    t1.bar = 'B';

    std::cout << t->foo << std::endl;

    /*
    t[0].foo = 1;
    t[0].bar = 'a';
    */
}



