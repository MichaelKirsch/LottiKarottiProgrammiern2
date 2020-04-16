

#include "Spielfeld.h"

void Spielfeld::erzeugen(int size) {

    for(int x=0;x<size;x++)
    {
        felder.emplace_back(Feld(x));
    }
    lochposition=size-1;
    felder[lochposition].istLoch=true;
    felder.shrink_to_fit();
}

void Spielfeld::drehenKarotte() {
    felder[lochposition].istLoch= false;
    lochposition = rand()%felder.size();
    felder[lochposition].istLoch = true;
    //std::cout << "Karotte wurde gedreht. Neues Loch bei: "<< lochposition << std::endl;
}
