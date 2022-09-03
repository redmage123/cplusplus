#include <iostream>
#include <stdio.h>


using namespace std;

int main() {

  char * foo = "bar";
  const int slope =2;
  const int b = 5;
  auto mylambda = [] (void) { cout << "This is a lambda function" << endl;};
  auto sum = [] (int x, int y) { return(x+y);};
  mylambda();
  printf("%d\n",sum(1,2));


  auto printfoo =  [&foo] (void) { printf("foo = %s\n",foo);};

  printfoo();

  auto getslope [=slope, =b] (int x) { return(slope *x) + b;};

  for (i=0;i< 10;[] (i) {return(i++);};) {
    printf("%d\n",i);
  }








}


