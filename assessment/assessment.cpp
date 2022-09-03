#include "assessment.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

String::String() {
    data = new char
    cerr << "Calling the default constructor" << endl;
}


String::String (const char * c) {
    int cLength;
    cLength = strlen(c);
    data = new char [cLength + 1]  ;
    fprintf(stderr,"length of data is %d\n",(int) strlen(data));
    data = strcpy(data,c);
}

String::~String() {
    cerr << "In the destructor";
        delete []  data;
}

String String::operator+=(const char * c) {
    data = strcat(data,c);
    return(*this);
}
    
String String::operator=(const char * c) {
    data = strcpy(data,c);
    return(*this);
}


