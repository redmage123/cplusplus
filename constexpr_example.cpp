#include <iostream>

using namespace std;
constexpr int product(int x, int y) 
{ 
    return (x * y); 
} 

int product2(int x, int y) {
    return (x* y);
}
  
int main() 
{ 
    const int x = product(10, 20); 
    const int y = product2(10,20);
    cout << x << endl; 
    return 0; 
} 
