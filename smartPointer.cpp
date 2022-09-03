#include <iostream>

class Data {
    int x;
    public:
        Data(int i = 42) : x{i} {};
        int get() {
            return x;
        }
};


template <class T> class Pointer {
    
    T* ptr;
    public: 
    Pointer(T * p = nullptr) : ptr{{p} {}
    T* operator -> () const {
        return ptr;
    }

};


int main() {
    Pointer <Data> p = new Data(10);
    p->get();
}

