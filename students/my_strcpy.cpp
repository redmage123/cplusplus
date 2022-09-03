#include <stdio.h>

char * strcpy(char * t, const char * s) {
    char * start = t;
    while (*t++ = *s++);
    return start;

}

int main() {
    char src[10] {"Hello"};
    char target[20];
    printf("Target = %s\n",strcpy(target,src));
}
