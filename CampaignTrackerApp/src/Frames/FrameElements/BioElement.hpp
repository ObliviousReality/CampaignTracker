#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class BioElement : public FrameElement
{
public:
    BioElement(EntityId id, EntityType type) : creatureId(id), entityType(type) {}
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

    EntityId getEntityId() const { return creatureId; }
    EntityType getEntityType() const { return entityType; }

private:
    EntityId creatureId;
    EntityType entityType;
};
