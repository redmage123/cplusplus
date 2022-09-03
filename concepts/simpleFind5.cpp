#include <iostream>
#include "inputter.h"


/*
 * Finally, we want to get rid of the equality test semantics in the
 * find iterator.  To do this, we'll create a Predicate functor
 * that we call lookFor. We'll pass this into the find iterator
 * as a predicate type.  Predicate types are types that return a boolean
 * expression as the result of some test.  In this case, we're testing
 * whether or not the character passed in is equal to the character being
 * looked for. 
 */


// The predicate operator.  Note that we overload the function () 
// operator to return a boolean if the initial value in the 
// constructor is the same as the value passed to the operator's
// parameter list. 
template <class T> class lookFor {
    T ch;
    public:
    lookFor(T c) : ch{c} {}
    bool operator() (T c) const {
        return c == ch;
    }
};

// Here we need to modify the template class to show that we now need
// to pass in a Predicate type as well as the Iterator type. Note that
// we don't need to pass in the end character as a separate parameter
// any longer.  It's passed in when the Predicate functor is put into
// the parameter list. 
template <class Iterator, class Predicate>
Iterator find (Iterator f, Iterator l, Predicate p) {

    // Now we no longer need to specify the == or != operators
    // explicitly, which means that the person calling the 
    // iterator can define exactly how the equality test expression
    // works for their container.
     
    while (f != l &&  !p(*f)) {
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

    // Custom predicate passed into the iterators parameter list. 
    Inputter r = find (start,stop,lookFor<char>('U'));
    if (r != stop) {
        std::cout<< "Found it!" << std::endl;
    }
}
