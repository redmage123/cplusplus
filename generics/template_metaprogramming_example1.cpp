#include <iostream>

using namespace std;

/* Here we declare a template structure called myFraction that
 * has two members, a Numerator and a Denominator.  Remember that
 * for template metaprogramming, all variables are static consts.
*/
template <int N, int D> struct myFraction {
    static const long Num = N;
    static const long Den = D;
};


/* We are also declaring another template structure called
 * ScalarMultiplication that takes two parameters, the first
 * is an integer, the second is a type, that will be passed in
 * at compile time. Notice that we declare result to be a type
 * of myFraction that takes the numerator from the typed parameter F
 * and multiplies it by the first parameter N. 
*/
template  <int N, typename F> struct ScalarMultiplication {
    typedef myFraction <N*F::Num, F::Den> result;
};


int main() {
    /* Here we're declaring mF1 as the myFraction type that we'll be
     * using a bit later.
    */
    typedef myFraction<2,3> mF1;

    /* Note that we're passing in the integer (2), as well 
     * as the type, in this case myFraction which is represented
     * by mF1.  The multiplication expression is now evaluated at
     * compile time and new value of mF2 is now in place.
     */
    typedef ScalarMultiplication<2,mF1>::result mF2;

    cout << mF2::Num<< "/" << mF2::Den<<endl;
}
