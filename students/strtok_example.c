#include <string.h>
#include <stdio.h>

int main() {

    char * str = "foo bar baz";

    char *token = strtok(str,' ');

    while (*token != '\0') {
        printf("%s\n", token);
        token = strtok(str, ' ');
    }


