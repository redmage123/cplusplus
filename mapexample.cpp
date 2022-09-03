#include <iostream>
#include <map>

using namespace std;

int main() {

    map <int,string> Employees;

    Employees[1234] = "Braun Brelin";
    Employees[1235] = "Joe Green";
    Employees[1236] = "James Black";
    Employees[1237] = "Edgar Blue";

    cout << "Employee 1235 is " << Employees[1235] << endl;
    cout << "Employee 1237 is " << Employees[1237] << endl;


    cout << "Map size: " << Employees.size() << endl;

    for (map<int,string>::iterator i = Employees.begin(); i != Employees.end(); ++i) {
        cout << (*i).first << ": " << (*i).second << endl;
    }

}

