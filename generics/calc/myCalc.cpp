template <class T> class myCalc {

    public: 
        myCalc();
        T add(T a, T b);
        T sub(T a, T b);
        T mul(T a, T b);
        T div(T a, T b);
}; 

using namespace std;

template <class T> myCalc<T>::myCalc() {
}

template <class T> T myCalc<T>::add(T a, T b) {
    return(a+b);
}

template <class T> T myCalc<T>::sub(T a, T b) {
    return(a);
}

template <class T> T myCalc<T>::mul(T a, T b) {
    return(a);
}
template <class T> T myCalc<T>::div(T a, T b) {
    return(a);
}
