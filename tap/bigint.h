#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
    private:
        int *  myinteger;
        int size;
    public: 
        BigInt( int  * n_array,int size ) : myinteger {new int [size]}  {
            for (int i = 0; i< size; i++) {
                myinteger[i] = n_array[i];
            }
            (*this).size = size;
        }
        ~BigInt() {
            delete []  myinteger;
        }
        BigInt(const BigInt &n); // Copy constructor 
        BigInt(BigInt &&n);  // Move constructor 
        BigInt &operator = (const BigInt &);  // Copy assignment operator 
        BigInt &operator = (BigInt &&); // Move assignments 
        BigInt &operator+= (const BigInt &);
        friend BigInt operator+(const BigInt &, const BigInt &);
};
#endif



b = b.somefunc(b1)
