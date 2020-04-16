

#include "Spiel.h"

Spiel::Spiel(int spielerAnzahl, int felder, int hasenprospieler) {
    feld.erzeugen(felder);
    for(int x =0;x<spielerAnzahl;x++)
    {
        alleSpieler.emplace_back(std::make_unique<Spieler>(x,hasenprospieler));
    }
}

void Spiel::run() {
    int Spielzug =0;
    bool keine_aktiven_hasen_mehr = false;
    while(!win&& !keine_aktiven_hasen_mehr)
    {
        for(auto& spieler:alleSpieler)
        {
            win = spieler->zieht(feld,stapel);
            if(win)
            {
                std::cout << "Spieler "<< spieler->getID() << " gewinnt!!" <<std::endl;
                break;
            }
        }

        bool nochaktivehasen = false;
        for(auto& spieler:alleSpieler)
        {
            if(spieler->verloreneHasen < spieler->maximaleHasen)
                nochaktivehasen= true;
        }
        if(!nochaktivehasen)
        {
            keine_aktiven_hasen_mehr = true;
            std::cout << "Keine Hasen Mehr" << std::endl;
        }
        std::cout << "Spielrunde:"<<Spielzug << " ";
        for(int x =0;x<feld.felder.size();x++)
        {
            auto z= feld.felder[x];
            if(z.istBesetzt)
            {
                std::cout << "*";
            }
            else if(z.istLoch)
                std::cout << "o";
            else
                std::cout << "_";
        }
        std::cout << std::endl;
        Spielzug++;
    }
}
