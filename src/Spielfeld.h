

#pragma once

#include <iostream>
#include <vector>
#include "Renderable.h"
struct Feld
{
    Feld(int id):position(id){
        //logging
    };
    bool istBesetzt = false;
    bool istLoch= false;
    const int position;
};


class Spielfeld : public Renderable{
public:
    Spielfeld(){};
    void update(){};
    void render(){};
    void erzeugen(int size=24);
    void drehenKarotte();
    ~Spielfeld() = default;
    std::vector<Feld> felder;
    int lochposition;
};



