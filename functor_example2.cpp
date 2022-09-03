#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class CountStrings {
    int stringLength;
    int counter;

    public:
    CountStrings(int l) {
        stringLength = l;
        counter=0;
    };
    int operator() (vector<string> s) {
        for (vector<string>::const_iterator i = s.begin(); i != s.end(); ++i) {
            
          if ((*i).length() <= stringLength) {
                counter++;
          }
        }
        return(counter);
    }
};


int main(void) {


    vector<string> s;
    CountStrings c(3);
    CountStrings c1(5);


    s.push_back("Red");
    s.push_back("Green");
    s.push_back("Blue");
    printf("%d\n",c(s));
    printf("%d\n",c1(s));
}


