

#pragma once

#include <vector>
#include "Kartenstapel.h"
#include "Spielfeld.h"
#include <iostream>
#include <memory>

struct Hase : public Renderable
{
    void update(){};
    void render(){};
    bool feldBesetztOderEnde(Karte& karte, Spielfeld& feld)
    {
        if(karte+feldID<=feld.felder.size())
            return (feld.felder[karte+feldID].istBesetzt);
        return true;
    }
    bool aktiv=false;
    bool tot = false;
    int feldID;
};

class Spieler : public Renderable {
public:
    Spieler(int SpielerID,int anzahlHasen);
    void update(){};
    void render(){};
    bool zieht(Spielfeld& feld, Kartenstapel& stapel);//spieler zieht. return 1 wenn er gewinnt
    ~Spieler(){std::cout << "Spieler wird erased"<<std::endl;};
    int letzterErzeugterHase=0;
    int maximaleHasen =0;
    int verloreneHasen = 0;
    int weitester_hase = 0;
    int getID(){ return m_ID;};
    std::vector<Hase>& getHasen(){return hasen;};
private:
    const int m_ID;
    std::vector<Hase> hasen;

    void neuenHasenSetzen(Karte* karte,Spielfeld* feld);
    bool hasenBewegen(Karte& karte,Spielfeld& feld);
protected:
};



