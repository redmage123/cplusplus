#include <iostream>

using namespace std;

class myVector {
    int x;
    int y;
    public:
//    static int count;
    myVector();
    myVector(int,int);
    myVector operator+(myVector);
    friend ostream& operator<<(ostream &, myVector);


};

ostream& operator<<(ostream& os, myVector v1) {
    os << v1.x << " " << v1.y << endl;
}
myVector::myVector(int x, int y) {
    this->x = x;
    this->y = y;
}

myVector::myVector() {
    x = 0;
    y = 0;
}


      
myVector myVector::operator+ (myVector v2) {
    myVector v3;
    v3.x = this->x+ v2.x;
    v3.y = this->y + v2.y;
    return(v3);
}

/*
myVector myVector::operator-(myVector v2) {
    myVector v3;
    v3.x = this.x- v2.x;
    v3.y = this.y - v2.y;
    return(v3);
}

myVector myVector::operator*(myVector v2) {
      myVector v3;
      v3.x = v1.x * v2.x + v1.y * v2.y;
      return(v3);
}

*/

int main(void) {

    myVector v1(2,3);
    myVector v2(3,4);
    myVector v3;

    v3 = v1 + v2;
    cout << v3;
    // cout << v3.count;
}
