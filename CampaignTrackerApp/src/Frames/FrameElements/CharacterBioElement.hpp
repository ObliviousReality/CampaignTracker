#pragma once

#include "BioElement.hpp"

#include "core/Core.hpp"

class CharacterBioElement : public BioElement
{
public:
    CharacterBioElement(CreatureId id) : BioElement(id, CreatureType::Character) {}

    void update() override {}

private:
    void drawCoreInfo() override;
    void drawStats() override;
    void drawSpells() override;
};
