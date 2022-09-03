#include <iostream>
#include <string.h>

using namespace std;

class pn {
    char *s;
    public:
        pn() {
            s = new char [1000];
        }
        pn(const char * c) {

            s = new char [strlen(c)+1];
            s = (char *) memset(s,0,(size_t) strlen(c)+1);
            s = strcpy(s,c);
        }
        ~pn() {
            cerr <<"Calling the destructor " << endl;
            delete [] s;
            s=nullptr;
        }

    char * returnData() {
        cerr << "In returnData" << endl;
        return(s);
    }

};

int main() {
    const char * d = "Hello";
    pn * pnArray = new pn [10];
    pnArray[1].~pn();
    pn *p = new (&pnArray+1) pn(d);
    cout << "p->returnData() = " << p->returnData() << endl;
    delete d;
    delete [] pnArray;
}

