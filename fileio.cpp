#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream FP;
    FP.open("shape_data");
    string shapetype;
    string  height_s;
    string  width_s;
    int height;
    int width;
    char outputbuf[100];
    if (FP.is_open()) {
        while (! FP.eof()) {
            getline(FP,shapetype,",");
            getline(FP, height_s,",");
            getline(FP, width_s,",");
            stringstream(height_s)  >> height;
            stringstream(width_s)  >> width;
            FP >> outputbuf;
            if (FP.eof())  {
                FP.ignore();
            } else {
                cout << outputbuf << endl;
            }
        }
    } else {
        cerr << "Error:  Unable to open file.  ";
        return(1);
    }
    FP.close();
    return(0);
}
