#include <iostream>
#include <thread>
#include <vector>


using namespace std;

typedef struct airlineSendPacket {
    string & airlineName;
    string & originCity;
    string & destinationCity;
    string & passengerName;
    struct datetime {
        int year;
        int month;
        int day;
        int hour;
        int minute;
    };
} t_aSP;

typedef struct airlineReturnPacket {
    string & passengerName;
    string & originCity;
    string & destinationCity;
    double price;
    struct datetime {
        int year;
        int month;
        int day;
        int hour;
        int minute;
    };
} t_aRP;

class AirlineQuery {
    protected:
        string & airlineName;
    public:
        AirlineQuery();
        t_aSP * copyData(t_ASP);
        virtual t_aSP * returnPrice(t_aSP *,t_aRP *)=0;
};

class AirIndiaQuery: AirlineQuery {
    public:
        t_aSP * returnPrice(t_aSP *, t_aRP *);
};

class Indigo: AirlineQuery {

    public:
        Indigo();
        t_aSP * returnPrice(t_aSP *, t_aRP *);
};

class JetAirways: AirlineQuery {
    public:
        JetAirways();
        t_aSP * returnPrice(t_aSP *, t_aRP *);
};

class AirlineInformation {
    private: 
        vector <AirlineQuery> airlines; 
        t_aSP * aSPptr;
        t_aRP * aRPptr;
    public:
        AirlineInformation(string & pName, string &oCity, string &dCity, int y, int m,int d, int h, int mn); 
        t_aRP queryAirline(t_aSP);
};
