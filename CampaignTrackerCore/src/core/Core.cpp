#include "Core.hpp"

#include "core/Store.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

EntityType CTCore::creatureTypeToEntityType(CreatureType ct)
{
    switch (ct)
    {
        case CreatureType::Player: return EntityType::Character;
        case CreatureType::NPC: return EntityType::Character;
        case CreatureType::Monster: return EntityType::Monster;
    }
    // TODO: Add assert
    return EntityType::Character;
}

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

EntityId CTCore::createCharacter(CreatureType ct)
{
    const auto id = store->getNextFreeId(EntityType::Character);
    createEntity(id, EntityType::Character, new Character(id, ct));
    return id;
}

EntityId CTCore::createMonster()
{
    const auto id = store->getNextFreeId(EntityType::Monster);
    createEntity(id, EntityType::Monster, new Monster(id));
    return id;
}
