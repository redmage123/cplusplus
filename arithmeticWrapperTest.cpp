#include <stdio.h>
#include "arithmeticWrapper.h"




int main() {


    arithmeticWrapper aW();
    int testresult;

    testresult=arithmeticWrapperAddTest(aW);
    if (testresult == 0) {
        printf("Add test passed!\n");
    }
}
    int arithmeticWrapperAddTest(arithmeticWrapper &aW) {
        int result;
         result = aW.add(2,2);
         assert(result == 4);
         result = aW.add(-2,-2);
         assert(result == -4);
         result = aW.add(-2,2);
         assert(result == 0);
         return(0);

    }

