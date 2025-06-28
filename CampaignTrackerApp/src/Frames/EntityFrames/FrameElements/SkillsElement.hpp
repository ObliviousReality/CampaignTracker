#pragma once

#include "Frames/FrameElement.hpp"

#include "core/Core.hpp"

class SkillsElement : public FrameElement
{
public:
    SkillsElement(EntityId playerId, EntityType typeIn) : id(playerId), type(typeIn) {}
    void update() override {}
    void draw() override;

private:
    EntityId id;
    EntityType type;
};
