#include <iostream>


class MyIntArray {

    int *  myiarray;
    int size;

    public:
        MyIntArray() {
        }
        MyIntArray(int * arr,int s) {
            size = s;
            myiarray = new int [size];
            for (int i = 0; i < size; i++) {
                myiarray[i] = arr[i];
            }
        }
        ~MyIntArray() {
            delete [] myiarray;
        }
        
        MyIntArray(const MyIntArray &mi) {
            std::cerr << "Calling copy constructor" << std::endl;
            myiarray = new int [mi.size];
            for (int i = 0; i < mi.size; i++) {
                myiarray[i] = mi.myiarray[i];
            }
        }
        
        MyIntArray & operator=(const MyIntArray &mi) {
            std::cerr << "Calling copy assignment operator" << std::endl;
            if (this == &mi) {
                return *this;
            }
            myiarray = new int [mi.size];
            for (int i = 0;i<mi.size;i++) {
               myiarray[i] = mi.myiarray[i]; 
            }
            return *this;
        }

        MyIntArray (MyIntArray && mi) {
            std::cerr << "In move constructor" << std::endl;
            myiarray = mi.myiarray;
            mi.myiarray = nullptr;
        }


        MyIntArray & operator=(MyIntArray &&mi) {
            if (this != &mi) {
                std::swap(myiarray,mi.myiarray);
            }
            return (*this);
        }





        void print() const {
            for (int i = 0; i< 10; i++) {
                std::cout << myiarray[i] << " ";
            }
            std::cout << std::endl;
        }
};


MyIntArray * foo() {
    int  test []  {11,12,13,14,15};
    int size = sizeof(test) / sizeof(test[0]);
    MyIntArray * x = new MyIntArray(test,size);
    return (x);
}


int main(void) {

    int  arr1[]  {0,1,2,3,4,5,6,7,8,9};
    int  arr2[]  {9,8,7,6,5,4,3,2,1,0};
    int arr_size = sizeof(arr1) /  sizeof(arr1[0]);

    MyIntArray i_arr1 (arr1,arr_size);
    MyIntArray i_arr2 (arr2,arr_size);
    MyIntArray i_arr3 = i_arr1;
    MyIntArray i_arr4;
    MyIntArray * i_arr5 = foo();
    i_arr4 = i_arr1;

    i_arr2.print();
    i_arr3.print();
}




  
