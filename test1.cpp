#include <iostream>
#include <string.h>


char * toupper(const char * s) {
    int i = 0;
    char * t = new char  [strlen(s)+ 1];
    while (s[i] != '\0') {
        t[i] =  s[i] - 32;
        i++;
    }

    t[i] = '\0';
    return (t);
}

char * toupper2(char * s) {
    while (*s != '\0') {
        std::cerr << "*s = " << *s << std::endl;
//        *s = *s - 32;
        *s = 'a';
        s++;
    }
    return (s);
}

int main() {
    char  * test_str = "hello world";
//    std::cout << toupper(test_str) << std::endl;
    std::cout << toupper2(test_str) << std::endl;
}

   
