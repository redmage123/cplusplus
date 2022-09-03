#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "Shapes.h"
using namespace std;


int main() {
//    vector<Shape *> shape_list;
//    Shape *  shape_list [2];
    vector<Shape *> shape_list;
    FILE * fp;
//    Rectangle rec(10,7);
//    Triangle tri(10,5);
    char outbuf[255];
    int i;
    char shapeType [50];
    int height;
    int width;
//    int shape_list_index=0;

    fp = fopen("shape_data","r");
    if (fp == NULL) {
        perror("Can't open file");
        return(1);
    }

    while ((fgets(outbuf,sizeof(outbuf),fp))) {
        cout << "outputbuffer = " <<outbuf;
        sscanf(outbuf,"%[^',']%[^',']%[^',']%d",shapeType,&height,&width);
        cout << "shapetype = " << shapeType << " Height = " << height << "Width = " << width << endl;
        if (strcmp(shapeType,"Rectangle")) {
            shape_list.push_back(new Rectangle(height,width));
        } else if (strcmp(shapeType,"Triangle")) {
            shape_list.push_back( new Triangle(height,width));
        } else {
            continue;
        }
    }






//    shape_list.push_back(&rec);
//   shape_list.push_back(&tri);
//     shape_list[0] = &rec;
//     shape_list[1] = &tri;

//    for (i=0;i< shape_list.size();i++) {
//       cout << shape_list[i]->area() << endl;
//  }

    for (i=0;i<2;i++) {
        cout << shape_list[i]->area() << endl;
    }
    fclose(fp);
    return 0;
}



