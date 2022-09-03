#include <iostream>
using namespace std;

class Dog {
    int age;
    string name;
public:
    Dog() {
        age = 5;
        name="Rex";
    }
    void setAge(const int &a) {
        age = a;
    }
    const string &getAge() {
        return(name);
    }

    void printDogName() const {
    // This function will not change any values of variables in the
    // member class.
        cout << name << endl;
    }

};


int main() {
    Dog d;
    int i = 4;
    d.setAge(i);
    cout << i << endl;
}


