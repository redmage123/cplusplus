#include <iostream>

int main() {

    enum {RED,YELLOW, AMBER=YELLOW,GREEN};

    std::cout << AMBER << std::endl;
}
