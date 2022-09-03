#include <iostream>

#include <string>


using namespace std;

int main() {

    string * s1;
    string s2 = "Hello";

    s1 = new string;

    *s1 = s2;

    cout << *s1 << endl;
    delete s1;
}
