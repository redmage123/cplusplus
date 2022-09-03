#include <iostream>

/* This is our second pass at "genericizing" our find 
 * iterator. 
 * 
 * 1.  By using a Template called T, we can now
 *     pass it any type of object, not just characters.
 * 
 * 2.  Now we understand why we needed to define the end character.
 *     this allows us to define any type of value as the end point
 */


// Note that the find function now takes three generic parameter types, 
// two <T> pointers which resolve at compile time  representing the lower
// and upper bounds of the type to iterate over and a <T>  which
// represents the thing to search for.  

template <class T> T*  find(T * f, T * l, T c) {


    // Now, our while loop runs in a deterministic fashion with the upper and
    // lower bound. 
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
 * Unlike the previous examples, now we're not passing a character array
 * into the find iterator, but an integer array.  We've genericized our
 * find iterator so that now, we can pass in any arbitrary collection of 
 * types (char, integer, float, custom objects, etc.).  
 */


int main() {

    int Numbers[] = {1,3,2,4,6,9,8,6,7};

    // Define our end point.
    int *endOfNumbers= Numbers + sizeof(Numbers)/sizeof(int);

// This find function only works on any generic type.
    int *ip = find(Numbers,endOfNumbers,8);

// We know that the find was successful if ip doesn't point to the same
// place as the last number plus one.
    if (ip != endOfNumbers) {
        std::cout << *ip << std::endl;
    }
}


/* But it's still not good enough.  We still have to pass pointers into the
 * iterator.  The iterator needs to know about operations like
 * increment, deference and comparison on the items in the collection,
 */
