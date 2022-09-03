#include <iosfwd>

/* Here we show an example of a customer iterator.  This iterator, 
 * instead of taking data from a memory store such as an array,
 * takes its data from standard input.  
 */

class Inputter {
    std::istream & in;
    char ch;

    public: 
    
    // Note that our constructor takes an istream reference as well as
    // a termination character. 
        Inputter(std::istream &i, char c = '\0')
            : in{i}, ch{c} {};

    // Here we overload the dereference '*' operator so that we 
    // return the character from the stream. 
    
        char operator * () const {
            return ch;
        }

        // Here we overload the ++ operator so that we can get to the next
        // character in the stream. 
        Inputter &operator ++ () {
            in.get(ch);
            return *this;
        }


        // Because we're overloading the char conversion operator, we can 
        // now use this iterator in any char context. 
        // We'll use this when we compare two characters for inequality. 
        
        operator char () const {
            return ch;
        }
};





