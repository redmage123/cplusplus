#include <iostream>
#include <stdio.h>

using namespace std;

int foo() {
     printf("foo\n");
     return(0);
}


int bar() {
     printf("bar\n");
     return(0);
}

int baz() {
     printf("baz\n");
     return(0);
}

int main() {


      int (*fptr1) (void);
      int (*fptr2) (void);
      int (*fptr3) (void);
      fptr1 = &foo;
      fptr2 = &bar;
      fptr3 = &baz;

      fptr1();
      (*fptr1)();
      fptr2();
      (*fptr2)();
      fptr3();
      (*fptr3)();
}





