#include <iostream>
#include <iosfwd>
#include <string>
#include <algorithm>


class Inputter {
    std::istream & in;
    char ch;

    public:
        Inputter(std::istream & i, char c = '\0')  : in{i}, ch(c) {}
        
    char operator * () const {
        return ch;
    }

    Inputter & operator ++ () {
        in.get(ch);
        return *this;
    }


    operator char () const {
        return ch;
    }
};

class Outputter {

    std::ostream & out;

    public: 
        Outputter (std::ostream &o) : out(o) {}

        Outputter & operator ++ () {
            return *this;
        }


        Outputter &operator=(char v) {
            out << v;
            return *this;
        }

        Outputter & operator*() {
            return *this;
        }
};


template <tyopename T>
class OutputterGen {
    std::ostream & out;
    public:
        OutputterGen(std::ostream & o):  out(o) {}

        OutputterGen operator ++ (int) {
            return *this;
        }

        OutputterGen &operator *() {
            return *this;
        }

        OutputterGen &operator=(T v) {
            str << v;
            return *this;
        }
};



        
template <class Iterator, class T> 
Iterator find (Iterator f, Iterator l, T c) {
    while (f != l && *f != c) {
        ++f;
    }

    return f;
}

template <class OutputIterator, class Iterator, class T> 
void copy(OutputIterator o, Iterator f, Iterator l, T c) {

    
    OutputIterator t = o;
    while (f != l && *f != c) {
        *t = *f;
        ++t;
        ++f;
    }
    *t = *f;
}


int main() {
    /*
    Inputter start {std::cin}, stop{std::cin,'\n'};
    Inputter r = find (start,stop,'U');
    Outputter start_o {std::cout}, stop_o {std::cout,'\n'};

    if (r != stop) {
        std::cout << "Found it!" << std::endl;
    }
    */



    int  input_arr[] = {1,2,3,4,5};
    int  iend =  sizeof(input_arr) / sizeof(input_arr[0]);
    int output_arr[iend] ;
    std::string s = "Hello World";
    std::string s1;

/*
    copy(output_arr,input_arr,input_arr+iend,input_arr[iend]);
    for (int i = 0; i< iend; i++) {
        std::cout << "output_arr [" <<  i << "] = " << output_arr[i] << std::endl;
    }
*/


    
    copy (back_inserter(s1),s.cbegin(),s.cend(),s.back());
    std::cout << s1 << std::endl;


    /*
    copy(start_o,start,stop,'\n');
    */

}
