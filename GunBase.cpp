// GunBase.cpp
#include "GunBase.h"

// just mandatory dummy initialization for static variables.
int GunBase::total = 0;
//
float GunBase::Speed(){
    return 100.0/Weight();
}
void GunBase::ExtraLoad(){
    cout << "default ExtraLoad code"  << endl;
}

GunBase* GunBase::Swap(GunBase *p1, GunBase *p2) {
    if (this!=p1 and this!=p2) {
        return 0;
    } // something wrong

    if (this==p2){
        GunBase* tempor=p2; p2=p1; p1=tempor;
    }
    p1->UnLoad();
    p2->Load();
    return p2;
}
