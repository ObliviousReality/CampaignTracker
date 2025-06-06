#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class BioElement : public FrameElement
{
public:
    BioElement(CreatureId id) : playerId(id) {}

    void update() override {}
    void draw() override;

private:
    CreatureId playerId;
};