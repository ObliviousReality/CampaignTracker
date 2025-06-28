#include "Character.hpp"

#include "core/Dice.hpp"

#include "data/HitPoint.hpp"

#include <cmath>

Character::Character(EntityId id, CreatureType ct) : Creature(id, EntityType::Character, ct)
{
    spellSlotManager = std::make_unique<SpellSlotManager>();
    if (ct == CreatureType::NPC)
    {
        markNPC();
    }
}

void Character::generateSkills()
{
    const int proficiencyBonus = static_cast<int>(std::ceil(static_cast<float>(level) / 4.0f)) + 1;
    setProficiency(proficiencyBonus);

    setSpeed(Core::getRaceSpeed(getRaceType()));

    generateHP();

    Creature::generateSkills();
}

void Character::generateHP()
{
    const auto dice = Core::getClassHPDice(getClassType());

    auto baseHP = Core::getDiceValue(dice);
    auto subsequentHP = Core::getDiceAverageValueR(dice);
    const auto conMod = getAbilityModifier(AbilityType::Constitution);
    subsequentHP += conMod;
    baseHP += conMod;

    if (raceType == RaceType::Dwarf)
    {
        baseHP++;
        subsequentHP += 1;
    };

    const auto newMaxHp = baseHP + ((getLevel() - 1) * subsequentHP);
    setMaxHitPoints(newMaxHp);
    setHitPoints(newMaxHp);
}
