#include <iostream>

using namespace std;

/* Just a simple class example to demonstrate the point below */
class myExample {
    string s;
    public:
    myExample(const char * s_input) {
        s = s_input;
    }

    string returnValue() {
        return(s);
    }
};

int main() {
    myExample *  m = new myExample(myExample("Hello"));
    myExample * m1 = new myExample[3] {myExample("Foo"),myExample("bar"),myExample("baz")};
    cout << m->returnValue() << endl;
//    delete m;  Oops!  Forgot to delete the memory and free it up!
    
/* Here we see that the semantics can get confusing */
    cout <<  m1->returnValue() << endl; // Which object does this refer to?  What string gets printed? 
    cout << m1[0].returnValue() << endl; // Is this the same as the previous value?
 
    delete [] m1;  // Don't forget to delete m1!  Also, don't forget to use the correct form of delete!
    return(0);
}
