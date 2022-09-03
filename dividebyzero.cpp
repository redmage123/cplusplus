#include <iostream>
#include <stdexcept>

using namespace std;
int intDiv (int numerator, int denominator) {
    if (denominator == 0) {
        throw overflow_error("Divide by zero exception");
    }
    return(numerator/denominator);
    }

int main(void) {
    int i = 0;

    try {
        i = intDiv(10,2);
    } catch(overflow_error e) {
        cout << e.what();
    }
    cout << i << endl;

    try {
        i = intDiv(10,0);
    } catch(overflow_error e) {
        cout << e.what() << endl;
    }

    return 0;
}
