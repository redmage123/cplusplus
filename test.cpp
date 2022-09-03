#include <iostream>
#inclue "test.h"
#include <stdio.h>

using namespace std;

int main() {

    Vector<cars *> car_list;
    int i;


//    Get data for car from file
     car_list.push_back(new cars(params));

     for (i=0;i< car_list.size();i++) {
         car_list[i]->changecolor("Blue");
     }


     for (i=0;i< car_list.size();i++) {
         delete car_list[i];
     }
}








}
