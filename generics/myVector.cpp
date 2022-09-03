#include "myVector.h"

template <class T>  myVector<T>::myVector() {
    capacity=0;
    size=0;
    buffer=0;
}

template <class T> myVector::myVector(unsigned int s) {
    mv_size = size;
    mv_capacity = 1 ;


template <class T> myVector<T>::myVector(const Vector<T> & v) {
    unsigned int i;
    size = v.size;
    capacity = v.capacity;
    buffer = new T[size];
    for (i = 0; i < size; i++) {
        buffer[i] = v.buffer[i];
    }
}

