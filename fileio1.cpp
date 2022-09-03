#include <iostream>
#include <stdio.h>
#include "shapes.h"

using namespace std;

int main () {
    FILE* FP;
    shape * shape_list[10];
    FP = fopen("shape_data","r");
    if (FP == NULL) {
         perror("Can't open file: ");
    }
    string shapetype;
    int height;
    int width;
    int shape_list_index=0

    char outputbuf[100];

    while (fgets(outputbuf,sizeof(outputbuf),FP)) {
        sscanf(outputbuf,"%s,%d,%d",shapetype,&height,&width);
        if (shapetype == "Rectangle" ) {
            shape_list[shape_list_index] = &Rectangle(height,width);
        } else if (shapetype == "Triangle" ) {
            shape_list[shape_list_index] = &Triangle(height,width);
        } else {
            continue;
        }
        shape_list_index++;
    }
    FP.close();
    return(0);
}

