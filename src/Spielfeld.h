

#pragma once

#include <iostream>
#include <vector>
struct Feld
{
    Feld(int id):position(id){
        //logging
    };
    bool istBesetzt = false;
    bool istLoch= false;
    const int position;
};


class Spielfeld {
public:
    Spielfeld(){};
    void erzeugen(int size=24);
    void drehenKarotte();
    ~Spielfeld() = default;
    std::vector<Feld> felder;
    int lochposition;
};



