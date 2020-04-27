

#include "Spieler.h"

Spieler::Spieler(int SpielerID, int anzahlHasen) :m_ID(SpielerID) {
    maximaleHasen = anzahlHasen;
    for(int x =0;x<maximaleHasen;x++)
    {
        hasen.emplace_back(Hase());
    }
    hasen.shrink_to_fit();
}

bool Spieler::zieht(Spielfeld &feld, Kartenstapel &stapel) {
    for(auto it = hasen.begin();it!=hasen.end();++it)
    {
        if(it->feldID==feld.lochposition && it->aktiv)
        {
            //std::cout << "Spieler" << m_ID << " hat einen Hasen verloren auf Position: "<<it->feldID<<std::endl;
            verloreneHasen++;
            feld.felder[feld.lochposition].istBesetzt = false;
            it->aktiv = false;
            it-> tot = true;
        }
    }

    Karte gezogeneKarte = stapel.karteZiehen();

    if(gezogeneKarte==karotteDrehen)
    {
        feld.drehenKarotte();
    }
    else
    {
        if(letzterErzeugterHase<maximaleHasen)
        {
            neuenHasenSetzen(&gezogeneKarte,&feld);
        } else
        {
            return (hasenBewegen(gezogeneKarte,feld));
        }
    }
    return false;
}

void Spieler::neuenHasenSetzen(Karte *karte, Spielfeld* feld) {
    int stepsNeeded = *karte;
    for(int x =0;x<feld->felder.size();x++)//step through all fields
    {
        if(!feld->felder[x].istBesetzt)
        {
            stepsNeeded--;
            if(stepsNeeded==0)
            {
                hasen[letzterErzeugterHase].aktiv = true;
                hasen[letzterErzeugterHase].feldID=x;
                feld->felder[x].istBesetzt = true;
            }
        }

    }

    letzterErzeugterHase++;
}

bool Spieler::hasenBewegen(Karte &karte, Spielfeld &feld) {
    int zuspringen = karte;
    bool irgendeinenHasenBewegt = false;
    for(int x =0;x<maximaleHasen;x++)
    {
        if(hasen[x].aktiv && !hasen[x].tot && !irgendeinenHasenBewegt) //wenn der hase noch lebt
        {
            if(hasen[x].feldID+zuspringen<=feld.felder.size())
            {
                if(!feld.felder[(hasen[x].feldID+zuspringen)].istBesetzt)
                {
                    irgendeinenHasenBewegt = true;
                    feld.felder[hasen[x].feldID].istBesetzt = false;//alte pos löschen
                    feld.felder[(hasen[x].feldID+zuspringen)].istBesetzt = true; //neue besetzen
                    hasen[x].feldID += zuspringen;
                    if(hasen[x].feldID==feld.felder.size())
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
