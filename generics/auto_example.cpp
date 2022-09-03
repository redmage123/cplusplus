#include <iostream>
#include <typeinfo>
#include <assert.h>
#include <string.h>

using namespace std;

int main() {

    auto x = 10; // Here the compiler figures out, from the initializer value
                 // of 10, that x is an int.
    int y=0;

    const char *t = " World";

    auto s = "Hello "; // auto looks at this and declares s to be a const char *
    string s1 ("Some default value here");
    auto name = s1; // Here it figures out that name is a string because
                    //   s1 (the initializer)  is a string

    y += x; // Note that we can now use x as an integer in an expression. 
    cout <<"The value of y is " << y << endl;
//    s = strcat ((char *) s,t); // This will give a segmentation violation
    cout << "The value of name is " << name << endl;

}
