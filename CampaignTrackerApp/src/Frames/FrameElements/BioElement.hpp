#pragma once

#include "FrameElement.hpp"

#include "entities/Player.hpp"

class BioElement : public FrameElement
{
public:
    BioElement(Player * p) : player(p) {}

    void update() override {}
    void draw() override;

private:
    Player * player;
};