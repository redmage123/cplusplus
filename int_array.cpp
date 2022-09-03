#include <iostream>


#include <string.h>
#include <algorithm>

class MyIntArray {

    private:
        int * data;
        int size;
        int remainingSlots;

    public:
        MyIntArray() {
            data = nullptr;
            size = 0;
        }

        MyIntArray(int * dptr,int s)  {
            std::cerr << "In constructor" << std::endl;
            size = s;
            data = new int [size];
            for (int i = 0; i< size;i++) {
                data[i] = dptr[i];
            }
        }

        MyIntArray(int s) : size(s) {
            if (size > 0) {
                data = new int [size];
            }
        }
        ~MyIntArray() {
            std::cerr << "In destructor" << std::endl;
            delete [] data;
        }


        void erase()  {
            delete [] data;
            data = nullptr;
            size = 0;
        }


        MyIntArray (const MyIntArray & m) {

            std::cerr << "In copy constructor" << std::endl;
            size = m.size;
            data = new int[size];
            memcpy(data,m.data,size);
            remainingSlots = size-m.size;
        }

        MyIntArray operator=(const MyIntArray & m) {

            std::cerr << "In copy assignment operator" << std::endl;
            delete [] data;
            size = m.size;
            data = new int [size];
            memcpy(data,m.data,size);
            return *this;
        }



        MyIntArray(MyIntArray &&m) {
            delete [] data;
            data = m.data;
            m.data = nullptr;
        }


        int & operator[] (int index) {
            std::cerr << "In the non-const operator [] function" << std::endl;
            if (index > size) {
                std::cerr << "Array index out of bounds" << std::endl;
                exit(1);
            }
            return (this->data[index]);
        }

        const int & operator[] (int index) const {
            std::cerr << "In the const operator [] function" << std::endl;
            if (index > size) {
                std::cerr << "Array index out of bounds" << std::endl;
                exit(1);
            }
            return (this->data[index]);
        }


        operator int * () {
            return (data);
        }


        bool push (int element) {
            if (remainingSlots == 0) {
                int * temp = new int [size * 2];
                memcpy(temp,data,size);
                remainingSlots =size;
                size*=2;
                temp[remainingSlots--] =element;
                data = temp;
                temp = nullptr;
            }
        }


//        friend  MyIntArray & operator+(MyIntArray &, MyIntArray &); 
};
/*
MyIntArray& operator+ (MyIntArray & lhs, MyIntArray & rhs) {
    MyIntArray temp; 
    int *dptr;
    temp.size = lhs.size + rhs.size;
    temp.data = new int [temp.size];
    dptr = lhs.data;
    for (int i = 0; i < lhs.size; i++) {
        *dptr = *(lhs.data);
    }
    for (int i = 0; i < rhs.size; i++) {
        *dptr = *(rhs.data);
    }
}
*/

int main() {
    std::cout << "In main" << std::endl;
    int test[] = {0,1,2,3,4,5,6,7,8,9};
    int test1[] = {9,8,7,6,5,4,3,2,1,0};
    int * test2;
    int size = sizeof(test) / sizeof(test[0]);
    MyIntArray i;
    MyIntArray j(test,size);
    MyIntArray m;
    m = j;
    std::cout << j[4] << std::endl;
    j[4]= 5;
    std::cout << j[4] << std::endl;
//    j.erase();
    test2 = (int *) j;
    std::cout << "Checking conversion operation" << std::endl;
    std::cout << *(test2 + 3) << std::endl;
    /*
    MyIntArray k(test1,size);
    MyIntArray m 
    MyIntArray n = k + m; 
    */
}

    

    







