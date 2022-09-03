#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;


class myString {

    char *  mystr;

    public:
        myString() {
            printf("In the default constructor\n");
            mystr = new char[10];
            strcpy(mystr,"Default");
        }
        myString(char * s) {
            fprintf(stderr,"In the non-default constructor\n");
            mystr = new char [strlen(s)];
            strncpy(mystr,s,strlen(s));
        }
        ~myString() {
            delete [] mystr;
        }

        myString(myString && ms) {
            fprintf(stderr,"In move constructor\n");
            mystr = ms.mystr;
            ms.mystr = NULL;
        }
        
        myString(const myString &ms) {
            cerr << "Calling copy constructor" << endl;
            mystr = new char [strlen(ms.mystr)];
            strncpy( mystr, ms.mystr,strlen(ms.mystr));
        }

        myString& operator=(myString&& ms) {
           printf("In move operator\n");
            if (this != &ms) {
                std::swap(mystr,ms.mystr);
             }
             return(*this);
        }

        myString & operator=(const myString &ms) {
          printf("In copy assignment\n");
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

myString * foo() {
    fprintf(stderr,"In foo, about to creat&e x\n");
    myString *  x = new myString;
    return(x);
}

int main(void) {

    myString s1("Hello World");
//    myString s2 = static_cast <myString &&>  (s1);
//    myString s2 = s1;
      printf("About to instatiate s2\n");
      myString s2 = *(foo());
      printf("%s\n",s2.getString());
    /*
    myString s3;
    printf("About to call move operator\n");
    s3 = s1;
    printf("s2 = %s\n",s2.getString());
    s1.changeString("Goodbye World");
    printf("s1 = %s\n",s1.getString());
    printf("s2 = %s\n",s2.getString());
    printf("s3 = %s\n",s3.getString());
    printf("Pass\n");
    */
}





  
