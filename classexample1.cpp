#include <iostream>
#include <typeinfo>
using namespace std;

class myRectangle {
    int x,y;
    public:
    void set_values(int,int);
    int area();
};

void myRectangle::set_values(int a, int b) {
    x = a;
    y = b;
}

int myRectangle::area(void) {
    return(x * y);
}

int main() {
    myRectangle rect;
    rect.set_values(3,4);
    cout << "area: "  << rect.area() << endl;
    cout << "rect is a " << typeid(rect) << endl;
    return(0);
}





