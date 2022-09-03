#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

template <class T> class stats {

    T * data;
    int size;
    T mean;
    public: 
        stats (T *d,int s) {
          data = new T [size];
          size = s;
          memcpy(data,d,s);
        }

        ~stats() {
            delete [] data;
        }

        stats(stats && s) {
            data = s.data;
            s.data = NULL;
        }

        const stats & operator=(const stats && s) {
            if (this == s) {
                return(*this);
            }
            delete [] data;
            data = s.data;
            s.data = NULL;
            return(*this);
        }

        T getMean() {
          // iterate through the data pointer add the numbers up, 
          // divide by the number of elements.;
          // return pointer
            T * index = data;
            for (int i = 0;i<size;i++) {
                mean += index[i];
            }
            mean /= size;
            return(mean);
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
     int i;
     const int  &myc = 10;
     vector<stats <double> > v;
     for (int j = 0;j<5;j++) {

         for (i=0;i<10;i++) {
             darray[i] = i;
         }
         stats<double> mystats(darray,10);
         v.push_back(static_cast < stats<double> &&> (mystats));
     }
     const_cast<int &>(myc)++;
     printf("myc = %d\n",myc);
     myc++;
     printf("myc = %d\n",myc);


}


    
