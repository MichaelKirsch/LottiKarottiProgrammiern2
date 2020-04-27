#include <iostream>
#include <ctime>
#include "Spiel.h"
#include <iostream>

int main() {
    srand(time(NULL));
    Spiel(4,36,4).run();
    return 0;
}
