#include <iostream>
#include <fstream>
#include <string>
#include <istream>

#define TRUE 1
#define FALSE 0

class MyFile {

private:
    static std::ifstream _file;

public:

    MyFile() {}
    
    ~MyFile() {
        if(_file.is_open())  {
            _file.close();
        }
    }
    
    void open(const char* filename) {
        _file.open(filename); 
    }
    
    bool isOpen() const {
        return (_file.is_open());
    }
    
    void close() {
        if (_file.is_open()) {
            _file.close();
        }

    }
    
    /*
    std::string readLine(std::string s) {
        return getline(<static_cast istream> (_file),s);
    }
    */
    
};


int main() {

// then we can use it like this
    MyFile f;
    f.open("boo.txt");

//SAFE - The MyFile destructor is guaranteed to run
//   loadFromFile(f);
}
