#pragma once

#include "entities/Character.hpp"
#include "entities/Creature.hpp"
#include "entities/Monster.hpp"

#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Sense.hpp"

#include <memory>
#include <vector>

namespace Details
{
    template<typename T>
    T * findObject(const std::vector<std::unique_ptr<T>> & vector, CreatureId id)
    {
        auto item = std::find_if(
            vector.begin(),
            vector.end(),
            [&id](const std::unique_ptr<T> & p) { return p->getId() == id; });
        if (item != vector.end())
        {
            return item->get();
        }
        return nullptr;
    }
}

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

    CreatureId createCharacter();

    CreatureId createMonster();

    Player * getCharacterFromId(const CreatureId id) const { return Details::findObject(characters, id); }

    Monster * getMonsterFromId(const CreatureId id) { return Details::findObject(monsters, id); }

    Creature * getCreature(const CreatureId id, const CreatureType type) const;


    const CreatureId getNewCreatureId() { return nextFreeId++; }

private:
    CTCore();

    static CTCore * core;

    std::vector<std::unique_ptr<Character>> characters;
    std::vector<std::unique_ptr<Monster>> monsters;

    CreatureId nextFreeId = 0;
};
