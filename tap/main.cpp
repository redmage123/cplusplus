#include <iostream>
#include "bigint.h"

BigInt getBigInt(int *,int);

int main(void) {
    int  n[5] = {1,2,3,4,5};
    int m[5] = {6,7,8,9,10};
    int size = sizeof(n)/sizeof(n[0]);
    BigInt b(n,sizeof(n)/sizeof(n[0]));
    BigInt b1(b);
    BigInt b2;
    b2 = b1; // Test copy assignment
    BigInt b3(getBigInt(n,size);
    BigInt b4 = getBigInt(n,size);
    std::cout << "Trying to call the move constructor" << std::endl;
    BigInt b6(getBigInt(n,size));
    BigInt a (n,size);
    BigInt b (m,size);
    BigInt c = a + b;

    // Not defined in the class.  You will have to do that.
    std::cout << BigInt b[0] << std::endl;
    b[2] = 10;
}


BigInt getBigInt(int * narr,int size) {
    return BigInt(narr,size);
}
