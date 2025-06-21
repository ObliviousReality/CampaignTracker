#include "Core.hpp"

#include "core/Store.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore()
{
    srand(static_cast<uint>(time(0)));
    store = std::make_unique<Store>();
}

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Character * CTCore::getCharacterFromId(const EntityId id)
{
    return static_cast<Character *>(getEntity(id, EntityType::Character));
}

Monster * CTCore::getMonsterFromId(const EntityId id)
{
    return static_cast<Monster *>(getEntity(id, EntityType::Monster));
}

EntityId CTCore::createCharacter()
{
    const auto id = store->getNextFreeId(EntityType::Character);
    createEntity(id, EntityType::Character, new Player(id));
    return id;
}

EntityId CTCore::createMonster()
{
    const auto id = store->getNextFreeId(EntityType::Monster);
    createEntity(id, EntityType::Monster, new Monster(id));
    return id;
}
