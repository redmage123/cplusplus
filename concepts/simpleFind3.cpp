#include <iostream>

/*  
 *   Okay.  So far so good.  We've managed to pass generic classes
 *   to the find function, but when trying to implement the find, we
 *   are still expecting to receive pointers and increment/decrement
 *   and compare them. 
 *
 *   Another problem is that we're calling this function a 'find' function.
 *   Maybe the calling program is not trying to do a find, maybe it's
 *   trying to iterate over the collection for another reason.
 *   So, let's refactor our code to turn it from a single function
 *   into a wrapper class that will allow the customer to do some sort
 *   of iteration with an end point on any type of collection that's given
 *   to us.  We'll change the find function to be an Iterator type that takes
 *   a start Iterator and and end Iterator and what to look for. 
 *
 * 
 */



// We've refactored our find function.  First of all, it's now a template
// class rather than a function. It no longer returns a pointer
// to a generic type, nor does it take pointers as parameters, intead
// it returns an iterator type and takes two iterator types as parameters.
// The idea is that the iterators themselves overload and define the
// various operators such as !=, ++, etc. We no longer assume
// that the operators refer to pointer arithmetic or boolean expression
// evaluation. 
template <class Iterator, class T> Iterator find(Iterator f, Iterator l, T c) {

        while (f != l && *f != c) {
            ++f;
       }

    //We no longer worry about having to return the null character since
    // we're bounding the parameterized type. Also we're returning a pointer 
    // to the generic type starting at the type value we're looking for,
    // or the end of the collection if we didn't find it. 

    return f;
}


/*
 * Even though it looks like we're still passing a character array into the
 * find iterator, the compiler now thinks of them as iterator types rather 
 * than just pointers to intrinsic types. 
 */


int main() {

    // Define our collection
    char Story[] = "Once Upon a Time ...";

    // Define our end point.
    char *endOfStory= Story + sizeof(Story);

// This find function now takes two iterators and a generic type 
// and returns an iterator.  Note that raw pointer types support all
// of the operators that iterators expect to use, so we can pass those
// directly to the find function as iterators. 
//
    char *p = find(Story,endOfStory,'U');

// We know that the find was successful if ip doesn't point to the same
// place as the last number plus one.
    if (p != endOfStory) {
        std::cout << p << std::endl;
    }
}


/*
 * Whew.  Now our find iterator can look through any type of data structure
 * that supports the concept of a one-dimensional sequence of elements. 
 * Now we can use *any* type of data structure, not just one that uses
 * pointer implementations.  
 */
