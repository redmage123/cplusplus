#include <iostream>
#include <string>

using namespace std;


int main() {

    const int BUFFERSIZE 128
    string mystr;
    cout << "Please enter your name: ";
    cin.width(BUFFERSIZE);
    cin >> mystr;
    cout << "You entered " << mystr << "\n";
}
