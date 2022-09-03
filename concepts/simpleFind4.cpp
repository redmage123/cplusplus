#include <iostream>
#include "inputter.h"


/*
 * Here is another implementation of the find, but this time, we're using
 * our custom Input Iterator class.  
 * Note that we still treat things the same way in the find, that is
 * we take an Iterator class, and we loop over it using the iterator 
 * operators such as ++, * and (). 
 * However, this iterator, instead of iterating over an array or a
 * character string, is iterating over standard input.
 */
template <class Iterator, class T>
Iterator find (Iterator f, Iterator l, T c) {
    while (f != l && *f != c) {
        ++f;
    }

    return f;
}


/*
 * Here in the main class, we've defined and declared our Input 
 * iterator and passed it to our find so that it uses this to do the
 * iteration
 */
int main() {
    // Custom iterators
    Inputter start(std::cin), stop (std::cin,'\n');

    Inputter r = find (start,stop,'U');
    if (r != stop) {
        std::cout<< "Found it!" << std::endl;
    }
}
