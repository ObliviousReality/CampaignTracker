#pragma once

#include "core/Store.hpp"

#include "entities/Character.hpp"
#include "entities/Creature.hpp"
#include "entities/Monster.hpp"

#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Sense.hpp"

#include <memory>

class CTCore
{
public:
    CTCore(CTCore const &) = delete;
    void operator=(CTCore const &) = delete;

    static CTCore * Get()
    {
        static CTCore * instance = new CTCore();
        return instance;
    }

    static void PrintHelloWorld();

    EntityId createCharacter(CreatureType ct = CreatureType::Player);

    EntityId createMonster();

    EntityId createMonsterTemplate();

    template<typename T>
    EntityId createObject(const EntityType type)
    {
        const auto id = store->getNextFreeId(type);
        createEntity(id, type, new T(id));
        return id;
    }

    Character * getCharacterFromId(const EntityId id);

    Monster * getMonsterFromId(const EntityId id);

    Entity * getEntity(EntityId id, EntityType type) { return store->getObject(id, type); }
    void createEntity(EntityId id, EntityType type, Entity * ptr) { store->addObject(id, type, ptr); }

    ObjectIterator getIterator(EntityType type) { return store->getIterator(type); }

    unsigned int getObjectCount(EntityType type) { return store->getObjectCount(type); }

    EntityType creatureTypeToEntityType(CreatureType ct);

private:
    CTCore();

    static CTCore * core;

    std::unique_ptr<Store> store;
};
