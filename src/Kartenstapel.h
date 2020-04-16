

#pragma once

#include <cstdlib>

enum Karte
{
    karotteDrehen=0,einsspringen,zweispringen,dreispringen
};

class Kartenstapel {
public:
    Kartenstapel(){};
    Karte karteZiehen();
    ~Kartenstapel() = default;

private:
protected:
};



