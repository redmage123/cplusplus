#include <iostream>

using namespace std;

/* This is a simple template function example.  This function returns 
 * the absolute value of the passed variable.  Note that we have no way
 * of knowing at compile time exactly *what* sort of variable is going
 * to be passed to the myABS function, hence we use a template function
*/
template <typename T> T const myABS(T const  i) {
    return (i<0 ? -i : i);
}

int main() {

    int i = -10;
    float f= -2.5;
    cout << myABS(i) << endl; // Here we're passing an int to myABS()
    cout << myABS(f) << endl; // Here we're passing a float to myABS()
}
