#include <iostream>
#include <string.h>
#include <stdlib.h>

int main() {

    int i = 10;
    int * i_ptr; 



    // * -- > Dereference operator
    // & -- > Reference operator


    /*
    i_ptr= &i;
    std::cout  << i_ptr << std::endl;


    std::cout << * i_ptr << std::endl;
    */


/*
    int i_array [5] {1,2,3,4,5};
    int * i_arr_ptr = i_array;

    std::cout << *i_arr_ptr << std::endl;

    i_arr_ptr ++;

    std::cout << *i_arr_ptr << std::endl;
*/

    const int BUF_SIZE = 50;
    char * foo = (char *) malloc(BUF_SIZE);

    if (foo == NULL) {
        <do+something_here>
    }

    if (foo == nullptr) {
        <do_something_here>
    }


    // What if the malloc fails?

    //char * foo = "Hello ";
    char * bar  = "World";
    foo = strcat(foo,(const char *) bar);
    std::cout<< foo << std::endl;
    free(foo);
}



