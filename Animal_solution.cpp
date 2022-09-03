#include <iostream>
#include <vector>

using namespace std;


class Shape {
    protected:
        int width,height;
        string shapeType;
    public:
        Shape (int a=0, int b=0)
        {
            width=a;
            height=b;
        }
        virtual int area() = 0; 
        virtual char * getShapeType() =0;
};

class Rectangle: public Shape {
    public:
        Rectangle(int a, int b):Shape(a,b) {
        }
        int area() {
            cout <<"Rectangle class area :" << endl;
            return(width*height);
        }
        char * getShapeType() {
            return("Rectangle");
        }
};

class Triangle:public Shape {
    public: 
        Triangle(int a, int b): Shape(a,b){
        }
        int area() {
            cout <<"Triangle class area : " << endl;
            return(width*height/2);
        }
        char * getShapeType() {
            return("Triangle");
        }
};

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



