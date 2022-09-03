#include <iostream>
#include <iomanip>

using namespace std;


void myfunc(int);
void myfunc(float);
int myfunc(int);
int myfunc(int,int);
float myfunc(float,string);

int main(void) {

    int a=10;
    float bval=5.01;
    myfunc(a);
    myfunc(bval);

}


void myfunc(int a) {
    cout << "a = " << a << endl;
    return;
}

void myfunc(float b) {
    cout << fixed << setprecision(2) << "b = " << b << endl;
    return;
 }

int myfunc(int a) {
    cout << "Another function overload example" << endl;
    return (0);
}


