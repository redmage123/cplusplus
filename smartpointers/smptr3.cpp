#include <iostream>
#include <memory>

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

/* Here we declare m and m1 to be unique_ptr's to myExample, rather than raw pointers.
 * Note that we don't need to delete them at the end.  When the smart pointer goes out
 * of scope, the destructor for the allocated object also gets called, if any. 
*/
int main() {
    unique_ptr <myExample> m (new myExample("Hello"));
    unique_ptr<myExample[]> m1  (new myExample[3] {myExample("Foo"),myExample("bar"),myExample("baz")});
    unique_ptr <myExample> m2;
    cout << m->returnValue() << endl;
    for (int i = 0; i< 3;i++) {
        cout << m1[i].returnValue() << endl;
    }

    /* A unique pointer means that only one reference can point to it at a time.  So, the copy
     * constructor and copy operator don't work.  The move semantics, however, do.
    */ 

    m2 = (unique_ptr<myExample> &&) m;
    cout << "bar = " << m2->returnValue() << endl;
}

