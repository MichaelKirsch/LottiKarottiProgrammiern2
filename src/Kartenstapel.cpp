

#include "Kartenstapel.h"

Karte Kartenstapel::karteZiehen() {
    int chance = rand()%100;
    if(chance<20)
        return Karte::karotteDrehen;
    if(chance>=20&& chance<50)
        return Karte::einsspringen;
    if(chance>=50&&chance<75)
        return Karte::zweispringen;
    if(chance>=75)
        return Karte::dreispringen;
    return zweispringen;
}
