#include <iostream>
#include <string.h>


class OCF {

    private:
       int *data;

    public:
       OCF (int i = 0)  {
           data = new int(i);
           std::cerr << "In constructor" << std::endl;
       }

       OCF (const OCF & o) {
           std::cerr << "In copy constructor" << std::endl;
           data = new int;
           memcpy(data,o.data,sizeof(int));
       }

       OCF operator=(const OCF & o) {
           std::cerr << "In copy operator" << std::endl;
           *data = *(o.data);
           return *this;
       }

       OCF (OCF && o) {
           std::cerr << "In move constructor" << std::endl;
           data = o.data;
           o.data = nullptr;
       }

       ~OCF() {
           delete data;
       }
};
     
OCF make() {
    OCF local;
    return local;
}
     
int main() {

   OCF a{ 3 };
   OCF b{ a };
   OCF c{ make() };
   OCF d;
   d=a;
}
