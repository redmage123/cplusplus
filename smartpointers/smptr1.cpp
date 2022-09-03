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

/* The problem with this program is that I forget to delete the 
 * memory pointed to by the m pointer.  This can cause memory leaks. 
*/
int main() {
    myExample *  m = new myExample(myExample("Hello"));
    cout << m->returnValue() << endl;
//    delete m;  Oops!  Forgot to delete the memory and free it up!
    return(0);
}
