

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
    void render();
    void update();
    ~Spiel() = default;

private:
    std::vector<Renderable*> allRenderAbleObjects;
    Spielfeld feld;
    Kartenstapel stapel;
    std::vector<std::shared_ptr<Spieler>> alleSpieler;
    bool win= false;
protected:
};



