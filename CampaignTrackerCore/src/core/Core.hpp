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
    CTCore();
    static void PrintHelloWorld();

    Player * createPlayer();

private:
    std::set<Creature *> creatures;
};
