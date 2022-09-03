#include <stdio.h>
#include <cmath>
using namespace std;

class ConvertToPolar {

    int x;
    int y;


    public:
        double  * polar;
        ConvertToPolar() {
            polar = new double[2];
        }

        ConvertToPolar (int a, int b) {
            x = a;
            y = b;
            polar = new double[2];
        }

        ~ConvertToPolar() {
            delete polar;
        }
        double * operator() (int x,int y) {
            printf("In overloaded operator function\n");
            polar[0] = sqrt((x*x) + (y*y));
            polar[1] = cos (x) / sin(y);
            return (polar);
        }
};


int main(void) {
    int my_x = 2;
    int my_y = 2;

    ConvertToPolar myConvert;
    myConvert(my_x,my_y);
    printf("About to print results\n");
    printf("r = %f theta = %f\n",myConvert.polar[0],myConvert.polar[1]);
}






