#ifndef VOLLADDIERER_HPP_
#define VOLLADDIERER_HPP_
#include "schnittstelle.hpp"
#include "schaltung.hpp"
#include "baustein.hpp"
#include "xor2.hpp"
#include "oder2.hpp"
#include "und2.hpp"
#include "halbaddierer.hpp"

class Volladdierer : public Schaltung
{
    friend void testFull(Volladdierer* voll); //wir setzen hier friend damit wir in der main Funktion die Tests ausführen können
    friend class Test;
private:
    /* data */
public:
    Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1);
    void update();
};

Volladdierer::Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1)
{
    name = "volladdierer";
    addEingang(e0);
    addEingang(e2);
    addEingang(e2);
    addAusgang(a0);
    addAusgang(a1);

    //hier erzeugen wir die benötigten Schnittstellen. Sie dienen als Ausgang um den ersten Halbaddierer mit dem zweiten zu verbinden
    Schnittstelle* i0 = new Schnittstelle();
    Schnittstelle* i1 = new Schnittstelle();
    Schnittstelle* i2 = new Schnittstelle();
    
    //hier erzeugen wir den ersten halbaddierer. Wie man sieht werden i0 und i1 dafür genutzt um die Signale an halb2 weiterzuleiten
    Halbaddierer* halb1 = new Halbaddierer(e0, e1, i0, i1);
    Halbaddierer* halb2 = new Halbaddierer(i0, e2, a0, i2);
    Oder2* o2 = new Oder2(i1, i2, a1);
    
    baustein.push_back(halb1);
    baustein.push_back(halb2);
    baustein.push_back(o2);
}

void Volladdierer::update(){
        baustein[0]->update(); //halb1
        baustein[1]->update(); //halb2
        baustein[2]->update(); //or

}
#endif
