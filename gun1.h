// gun1.h
#ifndef GUN1_H_
#define GUN1_H_

#ifndef GUNBASE_H_
#include "GunBase.h"
#endif
//
class Gun1 : public GunBase {
    public:
    Gun1();
    int Weight(); // must be here because pure virtual in base class
    void Load();  // must be here because pure virtual in base class
    void UnLoad();  // must be here because pure virtual in base class
    GunBase* Start(); // only here. not in Gun2
};
#endif /* GUN1_H_ */ 
