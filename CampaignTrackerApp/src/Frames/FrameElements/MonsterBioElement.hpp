#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class MonsterBioElement : public FrameElement
{
public:
    MonsterBioElement(CreatureId id) : monsterId(id) {}

    void update() override {}
    void draw() override;

private:
    CreatureId monsterId;
};