#include <iostream>

class BigInt {

    int * ptr;
    int size;

    BigInt (int size) {
        ptr = new int [size];
    }

    BigInt (BigInt && b2) {  // Move constructor.

        if (ptr != nullptr)
            delete [] ptr;
        }
        ptr = new int[b2.size];
        bcopy(b2,b1,b2.size);
        b2.ptr = delete [];
};


        

BigInt b1
BigInt b2


    }




