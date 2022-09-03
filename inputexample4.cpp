#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;


int main() {
    string inputstr;
    float price=0;
    int quantity=0;
    float amount;


    cout << "Enter price: ";
    getline (cin,inputstr);
    stringstream(inputstr)>> price;
    cout << "Enter quantity: ";
    getline (cin,inputstr);
    stringstream(inputstr) >> quantity;
    amount = float(price * quantity);
    cout << "Total price: "  << fixed << setprecision(2)  << amount << endl;
    return(0);
}


