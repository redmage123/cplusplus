#include <iostream>
#include <string>

class Shape {
    protected:
        int width,height;
        float radius;
        string shapeType;
    public:
        Shape (int, int);
        virtual int area() = 0; 
};

class Rectangle: public Shape {
    public:
        Rectangle(int a, int b):Shape(a,b) {
        }
};

class Triangle:public Shape {
    public: 
        Triangle(int a, int b): Shape(a,b){
        }
};

class Circle:public Shape {
    const float PI=3.1415926;
    public: 
    Circle(float r): Shape(r) {};
    float area(); 
    float circumference()l 
};





