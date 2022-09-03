#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

class myString {

    char *  mystr;

    public:
        myString() {
        }
        myString(char * s) {
            mystr = new char [strlen(s)];
            strncpy(mystr,s,strlen(s));
        }
        ~myString() {
            delete [] mystr;
        }
        
        myString(const myString &ms) {
            cerr << "Calling copy constructor" << endl;
            mystr = new char [strlen(ms.mystr)];
            strncpy( mystr, ms.mystr,strlen(ms.mystr));

        }
        
        myString & operator=(const myString &ms) {
            cerr << "Calling copy assignment operator" << endl;
            if (this == &ms) {
                return *this;
            }
            mystr = new char [strlen(ms.mystr)];
            strncpy( mystr, ms.mystr,strlen(ms.mystr));
            return *this;
        }

        void changeString(char * s) {
            strcpy(mystr,s);
        }
        char * getString() {
          return mystr;
        }
};

int main(void) {

    myString s1("Hello World");

//    myString s2 = s1;
    
    myString s3;
    s3 = s1;
    /*
    printf("s2 = %s\n",s2.getString());
    s1.changeString("Goodbye World");
    printf("s1 = %s\n",s1.getString());
    printf("s2 = %s\n",s2.getString());
    printf("s3 = %s\n",s3.getString());
    printf("Pass\n");
    */
}




  
