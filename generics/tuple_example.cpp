#include <iostream>
#include <tuple>

using namespace std;

// This is an example of using tuples in C++.  
int main() {

    /* Here we declare the tuple with first element an int, 
     * second element a const char * and finally a float
    */
    tuple <int, const char *, float> t1 { 1,"Hello World", 2.0};

    // This tuple has not yet been initialized with values
    tuple <int, const char *, float> t2;

    int i;
    const char * word;
    double d;

    // This "unpacks" the tuple into individual variables. 
    tie(i,word,d) = t1;

    // Here we see that the value of both the zeroth element of the tuple and 
    // of i, which we unpacked using the tie function in the
    // previous statement, are identical.
    cout << get<0>(t1) << endl;
    cout << i  << endl;

    // This is the opposite of tie.  This takes three values and packs them
    // into the tuple.
    t2 = make_tuple(10,"Goodbye World",3.5);
    cout << get<1>(t2) << endl;
}


