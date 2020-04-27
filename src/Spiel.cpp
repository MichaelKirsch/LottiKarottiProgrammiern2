

#include "Spiel.h"

Spiel::Spiel(int spielerAnzahl, int felder, int hasenprospieler) {
    m_feld.erzeugen(felder);
    m_toRender.emplace_back(&m_feld);
    for(int x =0;x<spielerAnzahl;x++)
    {
        auto pointerzuSpieler = m_alleSpieler.emplace_back(std::make_shared<Spieler>(x, hasenprospieler));
        m_toRender.emplace_back(pointerzuSpieler.get());
        for(auto& hase:pointerzuSpieler->getHasen())
        {
            m_toRender.emplace_back(&hase);
        }
    }
}

void Spiel::run() {
    int Spielzug =0;
    bool keine_aktiven_hasen_mehr = false;
    while(!m_win && !keine_aktiven_hasen_mehr)
    {
        for(auto& spieler:m_alleSpieler)
        {
            m_win = spieler->zieht(m_feld, m_stapel);
            if(m_win)
            {
                std::cout << "Spieler "<< spieler->getID() << " gewinnt!!" <<std::endl;
                break;
            }
        }
        if(!m_win)
        {
            bool nochaktivehasen = false;
            for(auto& spieler:m_alleSpieler)
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
            for(int x =0; x < m_feld.felder.size(); x++)
            {
                auto z= m_feld.felder[x];
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

            for(auto& obj:m_toRender)
            {
                obj->update();
                obj->render();
            }
        }
    }
}
