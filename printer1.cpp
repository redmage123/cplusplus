#include <iostream>
#include <utility>
  
class Cartridge {

    private:
       int level{ 10 };

    public:
       bool use() {
           if ( level == 0 ) {
               return false;
           }
           --level;
           return true;
       }
};
     
Printer makePrinter() {

       Printer p{ new Cartridge };
       return p;
 }
     
int main() {

    Printer p = makePrinter();
     
    int pages = 14;

    do {
        if ( p.print() ) {
           --pages;
        } else {
           std::cout << "Replacing Ink Cartridge" << std::endl;
           p.replace( new Cartridge );
        }
    } while( pages );
}
