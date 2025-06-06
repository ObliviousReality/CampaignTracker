#include "Core.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore() { srand(static_cast<uint>(time(0))); }

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer()
{
    Player * p = new Player();
    creatures.emplace(p);
    return p;
}
