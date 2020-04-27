

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
    bool aktiv=false;
    bool tot = false;
    int feldID = -1;
};
class Spieler : public Renderable {
public:
    Spieler(int SpielerID,int anzahlHasen);
    ~Spieler(){std::cout << "Spieler wird erased" << std::endl;};
    void update(){};
    void render(){};
    bool zieht(Spielfeld& feld, Kartenstapel& stapel);//spieler zieht. return 1 wenn er gewinnt
    int letzterErzeugterHase=0;
    int maximaleHasen =0;
    int verloreneHasen = 0;
    int getID(){ return m_ID;};
    std::vector<Hase>& getHasen(){return hasen;};
private:
    const int m_ID;
    std::vector<Hase> hasen;
    void neuerHase(Karte& karte, Spielfeld& feld);
    bool hasenBewegen(Karte& karte,Spielfeld& feld);
protected:
};



