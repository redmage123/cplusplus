#include <string.h>

    class String {
       char * data;
        public:
           String();
           String(char * c);
           String(const char *  c);
           ~String();

           String operator+=(const char * c);
           String operator=(const char * c);
    };
