#include <iostream>

/* This is an example of a simple find iterator. 
 * Let's detail the problems with this application.
 * 1.  It only understands characters.  I.e. I can't 
 * pass integer arrays or, indeed, any other type of 
 * collection into the find function.  
 * 
 * 2.  It makes the assumption that the collection is null
 *     terminated.  Again, this isn't true for other types 
 *     of collections. 


// Note that the find function takes two specific param types, char * and char
char * find(char * s, char c) {


// Note here that the while loop runs assuming that *s is a 'true' value, i.e.
// not null.  
// 
    while (*s && *s != c) {
        ++s;
    }

// We're assuming that if we don't find the character we're looking for,
// we'll return a null character.  Again, not useful for other types of 
// collections. 
    return *s == c ? s: 0;
}


int main() {
    char Story[] = "Once Upon a Time ...";

// This find function only works on character arrays. 
    char *p = find(Story,'U');

// Only if the character pointer p doesn't point to a null character do we print
// out the result of the find. 
    if (p) {
        std::cout << p << std::endl;
    }
}
