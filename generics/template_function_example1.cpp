#include <iostream>
#include <string.h>

using namespace std;

/* This is a standard template class for the myMax function, which returns
 * larger of the two parameters.  This works for standard numeric types,
 * such as int, float, double, etc.
 * But what if we want to get the max value of two strings?
 * As it stands, the myMax function would return the max value of the
 * pointers, rather than the max value of the strings pointed to, which 
 * isn't really very useful.
 */

template <class T> T myMax ( T a, T b) {
    return(a > b? a:b);
}


typedef const char * CP;


/* Here we're creating a template specialization for the max function.
 * Note that it returns a * const char * (CP is defined as such)
 * and takes two const char *'s * as parameters.
*/

template <> CP myMax <CP> (CP a, CP b) {
    return(strcmp(a,b) > 0 ? a:b);
}

int main() {
    int i = 10, j = 9;
    const char * x = "one";
    const char * y = "two";
    cout << myMax(i,j) << endl; // At runtime, the system determines that 
                              // i and j are integers, so it calls the 
                              // default max function

    cout << max(x,y) << endl; // At runtime, the system determines that
                              // x and y are const char *'s, so it calls
                              // the overloaded function

}

