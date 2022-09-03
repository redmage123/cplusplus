#ifndef MYCALC_H
#define MYCALC_H

template <class T> class myCalc {

    public: 
        myCalc();
        T add(T a, T b);
        T sub(T a, T b);
        T mul(T a, T b);
        T div(T a, T b);
}; 

#endif
