#include <iostream>
#include <utility>

#define TRUE 1
#define FALSE 0



  
class Cartridge {

    private:
       int level{ 10 };

    public:
       Cartridge() {}
       Cartridge (const Cartridge & c) {
           level = c.level;
       }

       bool use() {
           if ( level == 0 ) {
               return false;
           }
           --level;
           return true;
       }

};
     
class Printer {
    private:
        Cartridge  *cart;

    public: 
        Printer(Cartridge * c) : cart(c)  {}
        Printer (Printer && p ) {
            cart = p.cart;
            p.cart = nullptr;
        }

        ~Printer() {
            delete cart;
        }

        bool print() {

            if (! cart->use()) {
                return FALSE;
            } else {
                std::cout << "Printing" << std::endl;
                return TRUE;
            }
        }

        void replace(Cartridge *c)  {
            delete cart;
            cart = c;
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
