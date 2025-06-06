#include "Core.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore() { srand(static_cast<uint>(time(0))); }

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer()
{
    players.emplace_back(std::make_unique<Player>());
    return players.back().get();
}
