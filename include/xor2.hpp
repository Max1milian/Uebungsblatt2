#pragma once
#include "schnittstelle.hpp"
#include "baustein.hpp"
class Xor2 : public Baustein
{
private:
    /* data */
public:
    Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    ~Xor2();

    void update();
    void print();
};

Xor2::Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    name = "Xor2";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
}

void Xor2::print(){
    std::cout << name << std::endl;
    std::cout << "Eingang 0: Pegel = " << eingang.at(0)->getPegel() << std::endl;
    std::cout << "Eingang 1: Pegel = " << eingang.at(1)->getPegel() << std::endl;
    std::cout << "Ausgang 0: Pegel = " << ausgang.at(0)->getPegel() << std::endl;
}

void Xor2::update()
{

    //gleiches Spiel wie bei allen anderen Bausteinen auch, wenn einer der Eingänge undefined ist, ist auch der ausgang undefined
    if (eingang.at(0)->getPegel() == Schnittstelle::UNDEFINED || eingang.at(1)->getPegel() == Schnittstelle::UNDEFINED) 
    {
        ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
    }

    /*Wenn einer der beiden Eingänge High ist soll auch der Ausgang auf High geschaltet werden*/
    else if ((eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::LOW) || (eingang.at(0)->getPegel() == Schnittstelle::LOW && eingang.at(1)->getPegel() == Schnittstelle::HIGH))
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
    //Wenn beide Pegel auf High sind, soll er auf LOW schalten
    else if (eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::HIGH)
    {
        ausgang.at(0)->setPegel(Schnittstelle::LOW);
    }
}
