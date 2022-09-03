#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;

int main() {

    string mystr {"Hello"};
    for (char c: mystr) {
        cout << c;
    }
    cout << "\n";
}

