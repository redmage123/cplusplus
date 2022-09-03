#include <iostream>

class BigInt {

    int * ptr;
    int size;

    BigInt (int size) {
        ptr = new int [size];
    }

    BigInt (const &BigInt b2) { 

        if (ptr != nullptr)
            delete [] ptr;
        }
        ptr = new int[b2.size];
        bcopy(b2,b1,b2.size);
    }
};


        


    }




