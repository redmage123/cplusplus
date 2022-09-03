#include <iostream>
#include <memory>
#include <string.h>
#include <cassert>

#if defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
 
 
/* This is an example of using shared pointers to implement 'Copy-on-write'.  Copy on write is where
 * multiple callers can share the same resource which is initially indistinguishable.  Only when one
 * caller wants to overwrite some data pointed to by the resource does a copy of the resource get
 * created and passed to the caller.  
*/
using namespace std;
// A COW (Copy On Write) string class
class String {
    std::shared_ptr<char> str;
    public:
    /* Here we're creating a shared_ptr to point to the data resource.  We're also saying to use
     * the default deleter (default_delete) and telling it that the shared pointer is managing an
     * array of integers so that the default_delete method will call the proper delete[] function.
    */
        String(const char * str = "") : str(new char[strlen(str) + 1], std::default_delete<char[]>()) {
            strcpy(this->str.get(), str);
        }
                             
        const char * c_str() {
            return str.get();
        }

        /* Here's where we do the actual copy on write.  The function puts a new char into a specific index
         * of the character array.  We then call the reset() function from the shared_ptr object that creates
         * a new shared_ptr with the new managed object.
        */
        void set_char_at(size_t index, char newChar) {
        // clone the string
           char * newString = new char[strlen(str.get()) + 1];
           strcpy(newString, str.get());
        // Overwrite correct char
           newString[index] = newChar;
                                                                                                                                         
        //                                                                                                                                                        // Get the shared pointer to manage it.
            str.reset(newString);
        }
//                                                                                                                                         
       // Instrumentation only for use int tests
           int getUseCount() { return str.use_count(); }
                                                                                                                                                                                            
};

                                                                                                                                                                   
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
        t.set_char_at(1, 'z'); // Copy on write requested here.  t sets a new character 'z'  at position 1 of the array.
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
