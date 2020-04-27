

#include "Spiel.h"

Spiel::Spiel(int spielerAnzahl, int felder, int hasenprospieler) {
    feld.erzeugen(felder);
    allRenderAbleObjects.emplace_back(&feld);
    for(int x =0;x<spielerAnzahl;x++)
    {
        auto pointerzuSpieler = alleSpieler.emplace_back(std::make_shared<Spieler>(x,hasenprospieler));
        allRenderAbleObjects.emplace_back(pointerzuSpieler.get());
        for(auto& hase:pointerzuSpieler->getHasen())
        {
            allRenderAbleObjects.emplace_back(&hase);
        }
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

        for(auto& obj:allRenderAbleObjects)
        {
            obj->update();
            obj->render();
        }
    }
}
