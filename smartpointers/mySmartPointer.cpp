#include <iostream>

using namespace std;

class myData {
    private:
        char * data;
    public:
        myData(const char * c) {
            data = (char *) c;
        }

        const char * getValue() {
            return(data);
        }
};

class RefCnt {
    private:
        int count;
    public:
        void addRef() {
            count ++;
        }
        int Release() {
            return --count;
        }
};

/* This is a sample implementation of a Smart Pointer wrapper class.
 */
template <class T> class mySmptr {

    private:
        T  * ptr;
        RefCnt * reference;

    public:
        mySmptr() {
            ptr = NULL;
            reference=new RefCnt();
            reference->addRef();
        }

        mySmptr(T * p) {
            ptr = p;
            reference=new RefCnt();
            reference->addRef();
        }

        mySmptr(const mySmptr<T>& sp) {
            ptr = sp.ptr;
            reference=sp.reference;
            reference->addRef();
        }


        mySmptr<T> & operator = (const mySmptr<T>&sp) {
            if (this != sp) {
                if (reference->Release() == 0) {
                    delete ptr;
                    delete reference;
                }
            }
            ptr = sp.ptr;
            reference = sp.reference;
            reference->addRef();
        }

        ~mySmptr () {
            cerr << "In smart pointer destructor" << endl;
            if (reference->Release() == 0) {
                delete ptr;
                delete reference;
            }
        }

        operator T& () const {
            return (*ptr);
        }

        T* operator ->() {
            return (ptr);
        }
};



int main() {

    mySmptr<myData> p = (new myData("Hello World"));
    {
        mySmptr <myData> q = p;
        cout << "Printing q->getValue()" << endl;
        cout << q->getValue() << endl;
    }

    cout << "Printing q->getValue()" << endl;
    cout << p->getValue() << endl;
    return(0);
}
