#include <iostream>
#include <typeinfo>
#include <stdio.h>

using namespace std;

double division (int a, int b) {
  if (b == 0) {
    throw "Division by zero condition";
  }
  return (a/b);
}

int main(void) {
    int a = 10;
    int b = 0;
    double z;

    printf("%s\n",typeid(a).name());
    printf("%s\n",typeid(b).name());
    try {
        z = division(a,b);
        cout << z << endl;
    } catch(const char * ex) {
        cerr << "Error: " << ex << endl;
        cerr << "Goodbye" << endl;
    }

    return(0);
}
