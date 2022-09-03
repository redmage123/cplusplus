#include <iostream>
#include <string.h>

using namespace std;

typedef struct chairInfo {
    string _m;
    int  _s;
    string _c;
} cInfo;


typedef struct tableInfo {
    string _m;
    int  _s;
    string _c;
    float _l;
    float _w;
} tInfo;

class Table {
    string model;
    int stockCode;
    string color;
    float length;
    float width;

    public:
    Table() {
        model="Rectangular Table";
        stockCode=2;
        color="Brown";
        length = 1.5;
        width = 0.6;
    }

    Table(string m, int s, string c, float l, float w) {
        model = m;
        stockCode = s;
        color=c;
        length = l;
        width = w;
    }

    tInfo * returnInfo(tInfo * t_i ) {
        t_i->_m =model;
        t_i->_s  = stockCode;
        t_i->_c =color;
        t_i->_l = length;
        t_i->_w = width;
        return(t_i);
    }
};

class Chair {
    string model;
    int stockCode;
    string color;

    public:
    Chair() {
        model = "Plain";
        stockCode=1;
        string color="Black";
    }

    Chair(string m ,int s,string c) {
        model = m;
        stockCode = s;
        color=c;
    }

    cInfo * returnInfo(cInfo * c_i ) {
        c_i->_m =model;
        c_i->_s  = stockCode;
        c_i->_c =color;
        return(c_i);
    }
};

class DiningSet : public Chair, public Table {
    cInfo * c_i_ptr;
    tInfo * t_i_ptr;
    string c_m;
    string c_c;
    int c_s;
    string t_m;
    int t_s;
    string t_c;
    float t_l;
    float t_w;
    public:

        DiningSet()  : Chair( c_m, c_s, c_c), Table(t_m, t_s, t_c, t_l, t_w) {
            cerr << "c_m = " << c_m << endl;
            c_i_ptr = new cInfo[4];
            t_i_ptr = new tInfo;
        }

        DiningSet(string t_m, int t_s, string t_c, float t_l, float t_w, string c_m, int c_s, string c_c) :  DiningSet() {
             cerr << "in first constructor" << endl;
             cerr << "value of t_s is " << t_s << endl;
        }



        ~DiningSet() {
            delete [] c_i_ptr;
            delete t_i_ptr;
        }



};


int main() {
    DiningSet * d = new DiningSet("Georgian",1,"Brown", 10.1, 5.2, "Georgian",2,"Black");
    return(0);
}
        


