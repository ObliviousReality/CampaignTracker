#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class PlayerBioElement : public FrameElement
{
public:
    PlayerBioElement(CreatureId id) : playerId(id) {}

    void update() override {}
    void draw() override;

private:
    CreatureId playerId;
};