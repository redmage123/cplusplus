#include <stdio.h>
#include <unistd.h>
int main() {
    int x = 10;
    int y = 20;

    for(int i = 0; i< 10; i++) {
        x += 1;
        y+=2;
        sleep(10);
    }
}

