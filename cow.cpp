#include <iostream>
#include <memory>
 
#if defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
 
 
// A COW (Copy On Write) string class
class String {
        std::shared_ptr<char> str;
        public:
        String(const char * str = "") : str(new char[std::strlen(str) + 1], std::default_delete<char[]>()) {
            std::strcpy(this->str.get(), str);
        }
                
        const char * c_str() {
            return str.get();
        }
                                   
        void set_char_at(size_t index, char newChar) {
//      clone the string
            char * newString = new char[std::strlen(str.get()) + 1];
            strcpy(newString, str.get());
// Overwrite correct char
            newString[index] = newChar;
// Get the shared pointer to manage it.
            str.reset(newString);
        }
                                                                                                                                                                             
// Instrumentation only for use int tests
       int getUseCount() {
           return str.use_count();
       }
                                                                                                                                                                           
};
                                                                                                                                                                                 
#include <cassert>
using namespace std;
                                                                                                                                                                                
int main() {
               {
                   String s("abc");
                   assert(std::string("abc") == std::string(s.c_str()));
                   assert(1 == s.getUseCount());
               }

               {
                   String s("abc");
                   String t(s);
                   assert(std::string("abc") == std::string(t.c_str()));
                   assert(2 == s.getUseCount());
                   assert(2 == t.getUseCount());
               }
                                                                                                                                                                                {
                   String s("abc");
                   String t("def"); 
                   t = s; 
                   assert(std::string("abc") == std::string(t.c_str()));
                   // Both share the same representation 
                  assert(2 == s.getUseCount()); 
                  assert(2 == t.getUseCount());
               }

               { 
                   String s("abc");
                   String t(s);
                   t.set_char_at(1, 'z');
                   assert(std::string("azc") == std::string(t.c_str()));
                   assert(std::string("abc") == std::string(s.c_str()));
                   // The set_char_at causes the representations to be split
                   assert(1 == s.getUseCount());
                   assert(1 == t.getUseCount());
               }
#if defined(_DEBUG)
    if (_CrtDumpMemoryLeaks()) // You see messages in the output window when you run under the debugger.
        std::cout << "Leaks like a sieve" << std::endl;
#endif
}
