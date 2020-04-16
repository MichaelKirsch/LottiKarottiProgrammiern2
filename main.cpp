#include <iostream>
#include <ctime>
#include "Spiel.h"
int main() {
    srand(time(NULL));
    Spiel(4,100,4).run();
    return 0;
}
