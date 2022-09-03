#include <iostream>

using namespace std;

class myclass {
    static string mystring;
    public:
    string returnmystring();
    void setmystring(string);
};


string myclass::returnmystring() {
    return(myclass::mystring);
}

void myclass::setmystring(string s) {
    myclass::mystring = s;
}


int main(void) {
    myclass m;
    myclass m1;

    cout << m.returnmystring() << endl;
    cout << m1.returnmystring() << endl;
}

