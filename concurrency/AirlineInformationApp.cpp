#include "AirlineInformationApp.h"
#include <random>
#include <time.h>



t_aRP * AirlineQuery::copyData( t_aSP * t, t_aRP * r) {

    r->passengerName = t->passengerName;
    r->originCity = t->originCity;
    r->destinationCity = t_aSP->destinationCity;
    r->datetime.year = t->datetime.year;
    r->datetime.month = t->datetime.month;
    r->datetime.day = t->datetime.day;
    r->datetime.hour = t->datetime.hour;
    r->datetime.min = t->datetime.min;
    return(r);
}

Indigo::Indigo() {
    this->airlineName = "Indigo";
}

t_aRP * Indigo::returnPrice(t_aSP *t, t_aRP r) {
    int rand_time;
    srand(time(NULL));
    rand_time = rand()  % 250 + 50;

    r = copyData(t,r);
    r->price = 50.00;
    return(r);
}






     
    

