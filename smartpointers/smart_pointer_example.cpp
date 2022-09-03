#include <iostream>
#include <memory>

using namespace std;

class myClass {
    char * data;
    public:
    myClass() {
        data="foobar";
    }
    char * returnData() {
      return(data);
    }
};


typedef struct myStruct {
  char *data;
} ms;


int main() {
    myClass foo();
    unique_ptr<myClass> sPtr(new myClass());
    unique_ptr<ms> s2Ptr(new ms);
    s2Ptr->data = "BarBazBlech";
    printf("%s\n",sPtr->returnData());
    printf("%s\n",s2Ptr->data);

}




