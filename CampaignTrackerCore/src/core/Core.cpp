#include "Core.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore() { srand(static_cast<uint>(time(0))); }

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

CreatureId CTCore::createCharacter()
{
    const auto id = getNewCreatureId();
    characters.emplace_back(std::make_unique<Player>(id));
    return id;
}

CreatureId CTCore::createMonster()
{
    const auto id = getNewCreatureId();

    monsters.emplace_back(std::make_unique<Monster>(id));
    return id;
}

Creature * CTCore::getCreature(const CreatureId id, const CreatureType type) const
{
    switch (type)
    {
        case CreatureType::Character:
        {
            return Details::findObject(characters, id);
        }
        case CreatureType::Monster:
        {
            return Details::findObject(monsters, id);
        }
        default: break;
    }
    return nullptr;
}
