#include <string>
//using namespace std;

class cars {
    std::string brand;
    std::string owner;
    std::string model;
    std::string color;
    std::string trans_type;
    float enginesize;
    std::string fuel_type;
    int number_of_doors;
    int brake_horsepower;
    std::string approved_colors[3];
    public:
    cars(string,string,string,string,string,float,string,int,int);
    int change_color(string);
    float getEngineSize();
    int changeowner(string);
    int getbrake_horsepower();
};


cars::cars(std::string br, std::string ow, std::string mo, std::string co,std::string tr,
           float en, string fu, int no, int bh) {
    brand = br;
    owner = ow;
    model = mo;
    color  = co;
    trans_type = tr;
    enginesize =  en;
    fuel_type = fu;
    number_of_doors = no;
    brake_horsepower = bh;
    approved_colors[0] = "Red";
    approved_colors[1] = "Green";
    approved_colors[2] = "Blue";
}

int cars::change_color(string c) {
    int i;
    for (i=0;i<3;i++) {
        if (c == approved_colors[i]) {
            break;
        }
    }
    if (i == 3) {
        return(1);
    } else {
        color = c;
        return(0);
    }
}

float cars::getEngineSize() {
    return(enginesize);
}

int cars::changeowner(string o) {
    owner = o;
    return(0);
}

int cars::getbrakehorsepower() {
    return(brakehorse_power);
}







s
