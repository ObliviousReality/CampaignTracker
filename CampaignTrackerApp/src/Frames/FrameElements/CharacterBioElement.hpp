#pragma once

#include "BioElement.hpp"

#include "core/Core.hpp"

class CharacterBioElement : public BioElement
{
public:
    CharacterBioElement(EntityId id) : BioElement(id, EntityType::Character) {}

    void update() override {}

private:
    void drawCoreInfo() override;
    void drawStats() override;
    void drawSpells() override;
};
