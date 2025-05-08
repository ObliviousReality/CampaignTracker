#include "Attribute.hpp"

#include <cmath>

namespace
{
    const int getModifier(const int skillLevel) { return static_cast<int>(std::floor((skillLevel - 10) / 2)); }
};

const int Abilities::getAbility(const AbilityType type) const
{
    switch (type)
    {
        case AbilityType::Strength: return STR;
        case AbilityType::Dexterity: return DEX;
        case AbilityType::Constitution: return CON;
        case AbilityType::Intelligence: return INT;
        case AbilityType::Wisdom: return WIS;
        case AbilityType::Charisma: return CHA;
        default: return 0;
    }
}

void Abilities::setAbility(const AbilityType type, const int val)
{
    switch (type)
    {
        case AbilityType::Strength: STR = val; break;
        case AbilityType::Dexterity: DEX = val; break;
        case AbilityType::Constitution: CON = val; break;
        case AbilityType::Intelligence: INT = val; break;
        case AbilityType::Wisdom: WIS = val; break;
        case AbilityType::Charisma: CHA = val; break;
    }
}

const int Abilities::getModifier(const AbilityType at) const { return ::getModifier(getAbility(at)); }

const int Skills::getSkill(const SkillType st) const
{
    switch (st)
    {
        case SkillType::Acrobatics: return acrobatics;
        case SkillType::AnimalHandling: return animal_handling;
        case SkillType::Arcana: return arcana;
        case SkillType::Athletics: return athletics;
        case SkillType::Deception: return deception;
        case SkillType::History: return history;
        case SkillType::Insight: return insight;
        case SkillType::Intimidation: return intimidation;
        case SkillType::Investigation: return investigation;
        case SkillType::Medicine: return medicine;
        case SkillType::Nature: return nature;
        case SkillType::Perception: return perception;
        case SkillType::Performance: return performance;
        case SkillType::Persuasion: return persuasion;
        case SkillType::Religion: return religion;
        case SkillType::SleightOfHand: return sleight_of_hand;
        case SkillType::Stealth: return stealth;
        case SkillType::Survival: return survival;
        default: return 0;
    }
}

void Skills::setSkill(const SkillType st, const int val)
{
    switch (st)
    {
        case SkillType::Acrobatics: acrobatics = val; break;
        case SkillType::AnimalHandling: animal_handling = val; break;
        case SkillType::Arcana: arcana = val; break;
        case SkillType::Athletics: athletics = val; break;
        case SkillType::Deception: deception = val; break;
        case SkillType::History: history = val; break;
        case SkillType::Insight: insight = val; break;
        case SkillType::Intimidation: intimidation = val; break;
        case SkillType::Investigation: investigation = val; break;
        case SkillType::Medicine: medicine = val; break;
        case SkillType::Nature: nature = val; break;
        case SkillType::Perception: perception = val; break;
        case SkillType::Performance: performance = val; break;
        case SkillType::Persuasion: persuasion = val; break;
        case SkillType::Religion: religion = val; break;
        case SkillType::SleightOfHand: sleight_of_hand = val; break;
        case SkillType::Stealth: stealth = val; break;
        case SkillType::Survival: survival = val; break;
    }
}

const int Skills::getModifier(const SkillType st) const { return ::getModifier(getSkill(st)); }

const int PassiveSkills::getPassiveSkill(const PassiveSkillType pst) const
{
    switch (pst)
    {
        case PassiveSkillType::Perception: return perception;
        case PassiveSkillType::Investigation: return investigation;
        case PassiveSkillType::Insight: return insight;
        default: return 0;
    }
}

void PassiveSkills::setPassiveSkill(const PassiveSkillType pst, const int val)
{
    switch (pst)
    {
        case PassiveSkillType::Perception: perception = val; break;
        case PassiveSkillType::Investigation: investigation = val; break;
        case PassiveSkillType::Insight: insight = val; break;
    }
}
