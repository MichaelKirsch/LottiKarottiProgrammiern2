#include <iostream>
#include <ctime>
#include "Spiel.h"
#include <iostream>
#include <thread>
int main() {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    srand(time(NULL));
    Spiel(4,100,4).run();
    return 0;
}
