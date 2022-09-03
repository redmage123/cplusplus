#include <iostream>
using namespace std;

/* These template functions actually get evaluated at 
 * compile time, not run time.  This is why the result
 * variable is defined as a static const.  No need to 
 * change it at runtime.  
*/ 
template <int N> struct Factorial {
    static const int result = N * Factorial<N-1>::result;
};

/* This is the template specialization function.  This becomes
 * the base case for the recursion. When the Factorial<0> function
 * is called, the compiler evaluates this specialized function.
*/
template <> struct Factorial<0> {
    static const int result=1;
};


int main() {
    /* At compile time, the Factorial<5>::result expression
     * simply gets replaced by the value 120.
    */
    cout << Factorial<5>::result << endl;
    return(0);
}
