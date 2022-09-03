#include <iostream>


class MyIntArray {

    private
        int * data;
        int size;

    public: 

        MyIntArray() : data(nullptr), size(0) { }
        ~MyIntArray() {
            delete [] data;
        }







};

MyIntArray makeIntArray () {
    MyIntArray x;
    return (x);
}

/* What I need to create.

   1.  Default constructor
   2.  Overloaded Constructor
   3.  Destructor
   4.  Copy Constructor
   5.  Move  constructor
   6.  Copy Assignment operator.
   7.  Implement [] as both
       a.  RValue
       b.  LValue
   8.  Implement a conversion operator for int *. 
*/


int main() {
    int  test_data [] = {0,1,2,3,4,5,6,7,8,9};
    MyIntArray i;
    int arr_size = sizeof(test_data) / sizeof (test_data[0]);
    MyIntArray j (test_data,arr_size);
    MyIntArray  k=j;
    MyIntArray m = makeIntArray();
    MyIntArray n;
    n = m;
    std::cout << j[4] << std::endl;
    j[5] = 6;
    int * foo = (int *) j;

}

