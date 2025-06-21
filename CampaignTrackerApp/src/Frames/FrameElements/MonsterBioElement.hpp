#pragma once

#include "BioElement.hpp"

#include "core/Core.hpp"

class MonsterBioElement : public BioElement
{
public:
    MonsterBioElement(EntityId id) : BioElement(id, EntityType::Monster) {}

    void update() {}
private:
    virtual void drawCoreInfo() override;
    virtual void drawStats() override;
    virtual void drawSpells() override {}
};
