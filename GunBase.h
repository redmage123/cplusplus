// GunBase.h
#ifndef GUNBASE_H_
#define GUNBASE_H_
#include <iostream> // to std::cout
using namespace std;

class GunBase {
    public:
    static int total; // common variable to be used by all derivative classes
    int weight; // variable available by each derivative class
//
//-------------------------------------
// Speed() is implemented ONLY here but uses Weight() that is implemented ONLY in
// derivative classes.
    float Speed();
// So, Weight() must be declared here as pure virtual and be declared and implemented
// normally in e      ach and ALL derivative classes.
    virtual int Weight()=0;
//---------               -----------------------------
// Load() and UnLoad() are exposed by this class to main program, but are implemented
// ONLY in derivative classes,so they must be declared here as pure virtual class
// and be declared and implemented normally in each and all derivative classes.
    virtual void Load()=0;
    virtual void UnLoad()=0;
//-----------------                       ---------------------
// ExtraLoad() is exposed by this class to main program and has a "default"
// implementation here but also allows ANY derivative class to implement.
// In this case that implementation will be executed and not the "default".
    virtual void ExtraLoad();
//------------------------------------
// Swap() is implemented ONLY here. Handle pointers
    GunBase* Swap(GunBase*, GunBase*);
};
