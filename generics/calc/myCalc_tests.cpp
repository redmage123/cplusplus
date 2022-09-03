#include "myCalc.cpp"
#include <assert.h>


void testforintAdd(myCalc<int> m) {

   int result;
   result = m.add(1,2);
   assert(result == 3);
}

/*
void testforFloatAdd(myCalc<float> m) 
   float result;
   result = m.add(1.1,2.2);
   assert(result == 3.3);
}
*/

int main() {

    myCalc<int> mc;
//    myCalc<float> mcf;
    testforintAdd(mc);
//    testforfloatAdd(mcf);
}
