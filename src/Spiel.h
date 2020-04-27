

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
    std::vector<Renderable*> m_toRender;
    Spielfeld m_feld;
    Kartenstapel m_stapel;
    std::vector<std::shared_ptr<Spieler>> m_alleSpieler;
    bool m_win= false;
};



