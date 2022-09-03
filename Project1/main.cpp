#include <iostream>
#include <vector>
#include "Shapes.h"

using namespace std;


int main() {
    vector<Shape *> shape_list;
//    Shape *  shape_list [2];
    Rectangle rec(10,7);
    Triangle tri(10,5);
    int i;

    shape_list.push_back(&rec);
    shape_list.push_back(&tri);

    for (i=0;i< shape_list.size();i++) {
        cout << shape_list[i]->area() << endl;
    }

    for (i=0;i< shape_list.size();i++) {
        cout << shape_list[i]->getShapeType() << endl;
    }
    return 0;
}



