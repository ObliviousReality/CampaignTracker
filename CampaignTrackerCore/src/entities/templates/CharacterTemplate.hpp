#pragma once

#include "CreatureTemplate.hpp"

#include "data/Class.hpp"
#include "data/Race.hpp"
#include "data/SpellSlot.hpp"

#include <array>

class CharacterTemplate : public CreatureTemplate
{
public:
    CharacterTemplate(EntityId id) : CreatureTemplate(id, EntityType::CharacterTemplate) {}

    ClassType getClassType() const { return classType; }
    void setClassType(ClassType newClassType) { classType = newClassType; }

    RaceType getRaceType() const { return raceType; }
    void setRaceType(RaceType newRaceType) { raceType = newRaceType; }

    const SpellSlotArray & getSpellSlots() const { return spellSlots; }
    void setSpellSlots(const SpellSlotArray & slots) { spellSlots = slots; }

private:
    ClassType classType = {};
    RaceType raceType = {};

    SpellSlotArray spellSlots = {};
};
