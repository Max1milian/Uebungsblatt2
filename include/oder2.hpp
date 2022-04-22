#pragma once
#include "schnittstelle.hpp"
#include "baustein.hpp"
class Oder2 : Baustein
{
private:
    /* data */
public:
    Oder2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    ~Oder2();
    void update();
};

Oder2::Oder2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    name = "Oder2";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
}
void Oder2::update(){
    
}