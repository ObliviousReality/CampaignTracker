#pragma once

#include "Frames/Frame.hpp"

#include "entities/Creature.hpp"

#include <set>

class EntityBrowser : public Frame
{
public:
    EntityBrowser(CreatureType t, bool & winOpen);
    void update() override;
    void render() override;

private:
    CreatureType type;
    EntityType eType;
    std::set<EntityId> ids;

    bool & windowOpen;
};
