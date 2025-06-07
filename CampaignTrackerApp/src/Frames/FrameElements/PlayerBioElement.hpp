#pragma once

#include "BioElement.hpp"

#include "core/Core.hpp"

class PlayerBioElement : public BioElement
{
public:
    PlayerBioElement(CreatureId id) : BioElement(id, CreatureType::Player) {}

    void update() override {}
    void olddraw();

private:
    void drawCoreInfo() override;
    void drawStats() override;
    void drawSpells() override;
};