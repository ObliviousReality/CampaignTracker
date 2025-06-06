#include "Core.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

CTCore::CTCore() { srand(static_cast<uint>(time(0))); }

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer()
{
    players.emplace_back(std::make_unique<Player>(getNewCreatureId()));
    return players.back().get();
}

template <typename T>
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
}

Creature * CTCore::getCreatureFromId(const CreatureId id, const CreatureType type) const
{
    switch (type)
    {
        case CreatureType::Player:
        {
            return findObject(players, id);
        }
        case CreatureType::NPC:
        case CreatureType::Monster:
        case CreatureType::Other:
        default: return nullptr;
    }
    return nullptr;
}
