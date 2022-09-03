#include <stdio.h>
#include <iostream>

using namespace std;


void foo(int & x) {
  x++;
}

int main() {
  int i = 10;
  int &j = i;


  cout << "i = " << i << endl;
  cout << "j = " << j << endl;

  foo(i);
  cout << "j = " << j << endl;

}



