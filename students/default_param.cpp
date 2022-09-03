#include <iostream>


int test(char [], int=0, int=-1);

int main()  {

    test("Hello");
}

int test(char s[] , int x=0,int y = -1) {
    std::cout <<x << std::endl;
}
