#pragma once

#include <array>

static constexpr const size_t NumSpellSlots = 8;

using uint = unsigned int;

using SpellSlotArray = std::array<uint, NumSpellSlots>;

class SpellSlotManager
{
public:
    SpellSlotManager()
    {
        slots = SpellSlotArray();
        remaining = SpellSlotArray();
    }

    const int getTotalSpells(const uint slot) const { return slots[slot]; }
    const uint getRemainingSpells(const uint slot) { return remaining[slot]; }

    void setSlotTotal(const uint slot, const uint val) { slots[slot] = val; }
    void setSlotRemaining(const uint slot, const uint val) { remaining[slot] = val; }

    void useSpell(const uint slot)
    {
        if (remaining[slot])
        {
            remaining[slot]--;
        }
    }

    void restoreSpell(const uint slot)
    {
        if (remaining[slot] != slots[slot])
        {
            remaining[slot]++;
        }
    }

    void resetSpellSlot(const uint slot) { remaining[slot] = slots[slot]; }

    void reset() { remaining = slots; }

    const SpellSlotArray & getSpellSlots() const { return slots; }
    const SpellSlotArray & getRemainingSpellSlots() const { return remaining; }

private:
    SpellSlotArray slots;
    SpellSlotArray remaining;
};