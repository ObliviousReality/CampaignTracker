#pragma once

#include "Creature.hpp"

#include "data/SpellSlot.hpp"

#include <memory>
#include <string>

class Player : public Creature
{
public:
    Player(
        const std::string name,
        const ClassType ct,
        const RaceType rt,
        const std::string humanName,
        const int level,
        const std::pair<MoralityType, OrderType> alignment);

    const ClassType getClassType() const { return classType; }
    const RaceType getRaceType() const { return raceType; }

    const bool hasInspiration() { return inspiration; }
    void setInspiration(const bool newInsp) { inspiration = newInsp; }

    const std::string & getHumanName() const { return humanPlayerName; }

    const int getLevel() const { return level; }
    void setLevel(const int newLevel) { level = newLevel; }
    void levelUp() { level++; }

    void useSpell(const uint spellSlot) { spellSlotManager->useSpell(spellSlot); }
    void restoreSpell(const uint spellSlot) { spellSlotManager->restoreSpell(spellSlot); }
    void resetSpells() { spellSlotManager->reset(); }
    void resetSpell(const uint spellSlot) { spellSlotManager->resetSpellSlot(spellSlot); }
    const uint getTotalSpells(const uint spellSlot) const { return spellSlotManager->getTotalSpells(spellSlot); }
    const uint getRemainingSpells(const uint spellSlot) const
    {
        return spellSlotManager->getRemainingSpells(spellSlot);
    }

    void setSpellSlots(const std::array<uint, NumSpellSlots> & slots)
    {
        int s = 0;
        for (const auto slot : slots)
        {
            spellSlotManager->setSlotTotal(s, slots[s]);
            s++;
        }
        spellSlotManager->reset();
    }

    void setRemainingSpellSlots(const std::array<uint, NumSpellSlots> & slots)
    {
        int s = 0;
        for (const auto slot : slots)
        {
            spellSlotManager->setSlotRemaining(s, slots[s]);
            s++;
        }
    }

    const std::array<uint, NumSpellSlots> & getSpellSlots() const { return spellSlotManager->getSpellSlots(); }
    const std::array<uint, NumSpellSlots> & getRemainingSpellSlots() const
    {
        return spellSlotManager->getRemainingSpellSlots();
    }

    void generateSkills() override;

private:

    void generateHP();

private:
    ClassType classType;
    RaceType raceType;
    std::string humanPlayerName;
    bool inspiration = false;

    std::unique_ptr<SpellSlotManager> spellSlotManager;

    int level = 1;
};