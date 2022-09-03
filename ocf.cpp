#include <iostream>
#include <string.h>


class OCF {

    private:
       int *data;

    public:
       OCF (int i = 0) : data ( new int {i} ) {}

       OCF (const OCF & o) {
           data = new int;
           memcpy(data, o.data, sizeof(int));
};
     
OCF make() {
    OCF local;
    return local;
}
     
int main() {

   OCF a{ 3 };  <--- The  OCF constructor for object a
   OCF b{ a };  <--- The copy constructor for object a. 
   OCF c{ make() }; <--- The move constructor
   OCF d; 
   d=a; <--- The copy assignment operator
   OCF e;
   e = make(); <-- The move assignment operator. 

}
