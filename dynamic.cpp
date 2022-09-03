#include <iostream>

using namespace std;

int main(void) {
    int * b;
    int * a;

    struct newstruct {
        int a;
        float b;
    };

    typedef struct struct_example {
        int foo;
        char * bar;
        float baz;
    }se; 

    a = new int;

    b = new int[10];

    se *myse = new se;
    se *myse1 = new se[20];
    struct newstruct new_structure;

    delete a;
    delete b;
    delete myse;
    delete myse1;
}
