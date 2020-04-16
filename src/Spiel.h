

#pragma once

#include "Spielfeld.h"
#include "Spieler.h"
#include "Kartenstapel.h"
#include <memory>
#include <bitset>

class Spiel {
public:
    Spiel(int spieler=4, int felder=30, int hasenprospieler=4);
    void run();
    ~Spiel() = default;

private:
    Spielfeld feld;
    Kartenstapel stapel;
    std::vector<std::unique_ptr<Spieler>> alleSpieler;
    bool win= false;
protected:
};



