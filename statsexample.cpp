#include <iostream>
using namespace std;

template <class T> class stats {

    T * data;
    public: 
        stats (T * d) {
          data = d;
        }

        T getMean() {
          // iterate through the data pointer add the numbers up, 
          // divide by the number of elements.;
          // return pointer
          return(0);
        }
        T  getMedian () {
          // find the middle element.  If total number is even, avg two middle elements.
          return(0);
          }
        T getVariance () {
            return(0);
        }
        T getStdDev() {
            return(0);
        }
           // Square root of the variance 
};


int main() {

     double *darray = new double [10];
     stats<double> mystats(darray);

     cout << mystats.getVariance() << endl;
     cout << mystats.getStdDev() << endl;
}


    
