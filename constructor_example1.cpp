#inclucde <iostream>

class MyIntArray {
    private:
        int size;
        int * myiarray;

    public:  
        MyIntArray() {   // Default constructor
        };
        MyIntArray(int *, int); // Constructor
        ~MyIntArray();  // Destructor
        MyIntArray(const MyIntArray &); // Copy Constructor
        MyIntArray & operator=(const MyIntArray &); // Copy Assignment Operator
        MyIntArray(MyIntArray &&);  // Move Constructor
        MyIntArray & operator=(MyIntArray &&);// Move assignment operator


        void print() const;
};

MyIntArray::MyIntArray (int * p, int s) :  size(s) {
    myiarray = new int [size];
    for (int i = 0; i< size; i++) {
        myiarray[i] = p[i];
    }
}

MyIntArray::~MyIntArray() {
    delete [] myiarray;
}


MyIntArray::MyIntArray(const MyIntArray & mi) {
    MyIntArray temp;
    temp.myiarray = new int[mi.size];
    for (int i = 0; i < mi.size;i++) {
        temp.myiarray[i]  = myiarray[i];
    }
    temp.size = mi.size;
    return temp;
}

MyIntArray::MyIntArray & operator=(const MyIntArray &mi) {
    if (this == &mi) {
        return (*this);
    }
}


MyIntArray::MyIntArray (MyIntArray && mi) {



int main() {

    MyIntArray a ();

    a = a;




}

MyIntArray & createinstance() {
    return MyIntArray(...);
}

int main() {

    MyIarray foo(...);

    MyIarray bar = a; // Copy constructor
    MyIarray blech = createinstance();  //  Move constructor
    MyIrray baz;

    baz = foo; //  Copy assignment operator.



    








