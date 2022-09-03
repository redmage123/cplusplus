#include "Shapes.h"

using namespace std;

Shape::Shape(int a, int b=0) {
    width = a;
    height = b;
}

Shape::Shape (float r) {
    radius = r;
}

Rectangle::Rectangle(int a, int b):Shape(a,b) {};
int Rectangle::area() {
    return(width * height);
}

Triangle::Triangle:public Shape {};
int Triangle::area() {
    return(width * height / 2);
}

Circle::Circle:public Shape(r) {};
float Circle::area() {
      return(PI * (radius * radius));
}
float Circle::circumference() {
    return(2 * pi * radius);
}
