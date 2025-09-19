#include "Creature.hpp"

#include <array>

void Creature::setTaggedSkills(const std::vector<SkillType> & skills, const int tagLevel)
{
    for (const auto skill : skills)
    {
        setTaggedSkill(skill, tagLevel);
    }
}

void Creature::setTaggedSavingThrows(const std::vector<AbilityType> & savingThrows, const int tagLevel)
{
    for (const auto savingThrow : savingThrows)
    {
        setTaggedSavingThrow(savingThrow, tagLevel);
    }
}

void Creature::generateSkills()
{
    const auto prof = getProficiency();
    auto setSkillLevel = [&](const SkillType st, const int base)
    { setSkill(st, base + (prof * getTaggedSkillLevel(st))); };

    // Str skills
    const auto str = getModifier(AbilityType::Strength);
    setSkillLevel(SkillType::Athletics, str);

    // Dex skills
    const auto dex = getModifier(AbilityType::Dexterity);
    setSkillLevel(SkillType::Acrobatics, dex);
    setSkillLevel(SkillType::SleightOfHand, dex);
    setSkillLevel(SkillType::Stealth, dex);

    // no con skills

    // Int skills
    const auto intel = getModifier(AbilityType::Intelligence);
    setSkillLevel(SkillType::Arcana, intel);
    setSkillLevel(SkillType::History, intel);
    setSkillLevel(SkillType::Investigation, intel);
    setSkillLevel(SkillType::Nature, intel);
    setSkillLevel(SkillType::Religion, intel);

    // Wis skills
    const auto wis = getModifier(AbilityType::Wisdom);
    setSkillLevel(SkillType::AnimalHandling, wis);
    setSkillLevel(SkillType::Insight, wis);
    setSkillLevel(SkillType::Medicine, wis);
    setSkillLevel(SkillType::Perception, wis);
    setSkillLevel(SkillType::Survival, wis);

    // Cha skills
    const auto cha = getModifier(AbilityType::Charisma);
    setSkillLevel(SkillType::Deception, cha);
    setSkillLevel(SkillType::Intimidation, cha);
    setSkillLevel(SkillType::Performance, cha);
    setSkillLevel(SkillType::Persuasion, cha);

    // passives

    auto getPassiveSkill = [&](const SkillType st)
    {
        auto mod = (getSkill(st));
        auto ad = (hasAdvantage(st) ? 5 : 0);
        auto dd(hasDisadvantage(st) ? 5 : 0);

        return 10 + mod + ad - dd;
    };

    setPassiveSkill(PassiveSkillType::Perception, getPassiveSkill(SkillType::Perception));
    setPassiveSkill(PassiveSkillType::Insight, getPassiveSkill(SkillType::Insight));
    setPassiveSkill(PassiveSkillType::Investigation, getPassiveSkill(SkillType::Investigation));

    setInitiative(getModifier(AbilityType::Dexterity));
}
