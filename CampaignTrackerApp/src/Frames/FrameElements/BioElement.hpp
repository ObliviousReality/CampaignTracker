#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class BioElement : public FrameElement
{
public:
    BioElement(CreatureId id, CreatureType type) : creatureId(id), creatureType(type) {}
    void draw() override;

protected:
    virtual void drawCoreInfo() = 0;

    void drawAbilities();
    void drawSavingThrows();
    void drawHitPoints();
    virtual void drawStats() = 0;
    void drawPassives();
    virtual void drawSpells() = 0;
    void drawOtherDetails();

    CreatureId getCreatureId() const { return creatureId; }
    CreatureType getCreatureType() const { return creatureType; }
private:
    CreatureId creatureId;
    CreatureType creatureType;
};