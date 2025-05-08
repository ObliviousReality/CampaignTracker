#pragma once

#include "entities/Creature.hpp"
#include "entities/Player.hpp"

#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Sense.hpp"

#include <memory>
#include <set>


class CTCore
{
public:
    CTCore() {}
    static void PrintHelloWorld();

    Creature * createCreature(const std::string & name);
    Player * createPlayer(
        const std::string & name,
        const ClassType classType,
        const RaceType raceType,
        const std::string & human,
        const int level,
        const std::pair<MoralityType, OrderType> alignment);

private:
    std::set<Creature *> creatures;
};
