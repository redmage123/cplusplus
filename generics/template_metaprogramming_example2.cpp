#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

/* This is the template structure that will implement the adding of two numbers
 * at compile time.  
template <bool B> struct Algorithm {
    template<class T1, class T2> static auto add(T1 && a, T2 && b) {
        return (a+b);
    }
};


/* This is a specialization of the Algorithm in the case that a boolean
 * false value gets passed to it rather than a true
*/
template <> struct Algorithm<false> {
    template<class T1, class T2> static auto add( T1 && a, T2&& b) {
        cerr << "The parameters passed aren't numeric" << endl;
        return(a+b);
    }
};


/* Here we call the add method within the Algorithm struct template.
 * Note that the is_arithmetic() function is defined in std. It returns a
 * true if the parameter passed into it can be plugged into an arithmetic
 * formula, false otherwise.
 * So, for example, if a and b are both numeric, then the first definition
 * of Algorithm is called, however, if either of these parameters are
 * non-numeric, than is_arithmetic returns a false value.  On a boolean
 * 'and' operation, if either value is false, the entire expression is false.
 * Therefore, the partial specialization template is called.
*/

template<class T1, class T2> auto execute (T1 && a, T2 && b) {
    return(Algorithm(is_arithmetic<T1>::value && 
                        is_arithmetic<T2>::value>::add(a,b)));
}

int main() {
    cout << execute(10,20) << endl;  //Calling the execute class "constructor"
    cout << execute(string("Hello "),string("World") << endl
    cout << execute (10.3,20) << endl;
    char buffer [] = "Well, this was fun (not!)";
    cout << execute(buffer,14) << endl;


