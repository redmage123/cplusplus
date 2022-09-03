#include <iostream>
#include <utility>

using namespace std;
class myRectangle {
//    int x,y;
    pair<int,int> coords;
    public:
    myRectangle(int, int);
    myRectangle();
    void set_values(int,int);
    pair<int,int> get_values();
    int area();
};

myRectangle::myRectangle (int a, int b) {
    coords.first = a;
    coords.second =  b;
}
myRectangle::myRectangle() {
    coords.first = 1;
    coords.second = 1;
}


void myRectangle::set_values(int a, int b) {
    coords.first = a;
    coords.second =  b;
}

int myRectangle::area(void) {
    return(coords.first * coords.second);
}

pair <int,int> myRectangle::get_values() {
        return(coords);
}

int main() {
    myRectangle rect(1,2);
    myRectangle rect1;
    cout << "area: "  << rect.area() << endl;
    rect.set_values(3,4);
    cout << "area: "  << rect.area() << endl;
    return(0);
}





