#include "Core.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore() { srand(static_cast<uint>(time(0))); }

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer(
    const std::string & name,
    const ClassType classType,
    const RaceType raceType,
    const std::string & human,
    const int level,
    const std::pair<MoralityType, OrderType> alignment)
{
    Player * p = new Player(name, classType, raceType, human, level, alignment);
    creatures.emplace(p);
    return p;
}

Creature * CTCore::createCreature(const std::string & name)
{
    Creature * c = new Creature(name, { MoralityType::None, OrderType::None });
    creatures.emplace(c);
    return c;
}
