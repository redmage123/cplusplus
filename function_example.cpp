#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

/* This example shows both the std::function and the std::bind 
 * functions available within the standard library.  
*/

// The next three functions are the test example functions 
void func1() {
    cout << "In func1" << endl;
}

int square(int x) {
    return(x* x);
}

int mul(int x,int y) {
    return (x * y);
}

int main()  {
    /* Here we see the use of the std::function method. The std::function
     * method allows us to call functions through variables. This is 
     * generally a better choice than function pointers if, for example
     * you want to store and then call a 'callback' function. 
    */
    function<void()> f1 = func1;
    function<int(int)> f2 = square;

    /* This third example shows the use of the std::bind method to allow
     * us to pass parameters into a function via the stored object at runtime.
     * Here we bind the _1 to whatever param gets passed in by the variable
     * it calls the function, in this case we'll pass in a '2' to the bound
     * parameter.
    */
    function<int(int)> f3 = bind(mul,_1,3);

    f1();
    cout << f2(2)<< endl;
    cout << f3(2)<< endl; // Passing a '2' to the bound param. 
}


