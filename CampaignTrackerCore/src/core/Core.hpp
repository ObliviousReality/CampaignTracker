#pragma once

#include "entities/Creature.hpp"
#include "entities/Player.hpp"

#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Sense.hpp"

#include <memory>
#include <vector>

class CTCore
{
public:
    CTCore();
    static void PrintHelloWorld();

    Player * createPlayer();

    Creature * getCreatureFromId(const CreatureId id, const CreatureType type) const;

    const CreatureId getNewCreatureId() { return nextFreeId++; }

private:
    std::vector<std::unique_ptr<Player>> players;
    // std::vector<std::unique_ptr<NPC>> npcs;
    // std::vector<std::unique_ptr<Monster>> monsters;

    CreatureId nextFreeId = 0;
};
