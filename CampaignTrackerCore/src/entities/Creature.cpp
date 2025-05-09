#include "Creature.hpp"

#include <array>

Creature::Creature(const std::string name, const std::pair<MoralityType, OrderType> alignment) : name(name)
{
    abilities = std::make_unique<Abilities>();
    skills = std::make_unique<Skills>();
    passives = std::make_unique<PassiveSkills>();

    morality = alignment.first;
    order = alignment.second;
}

void Creature::setTaggedSkills(const std::vector<SkillType> & skills, const int tagLevel)
{
    for (const auto skill : skills)
    {
        setTaggedSkill(skill, tagLevel);
    }
}

void Creature::setAbilities(const std::array<int, static_cast<size_t>(AbilityType::NUM_ABILITIES)> & abilities) const
{
    int count = 0;
    for (const auto ab : abilities)
    {
        setAbility(static_cast<AbilityType>(count++), ab);
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
    const auto str = abilities->getModifier(AbilityType::Strength);
    setSkillLevel(SkillType::Athletics, str);

    // Dex skills
    const auto dex = abilities->getModifier(AbilityType::Dexterity);
    setSkillLevel(SkillType::Acrobatics, dex);
    setSkillLevel(SkillType::SleightOfHand, dex);
    setSkillLevel(SkillType::Stealth, dex);

    // no con skills

    // Int skills
    const auto intel = abilities->getModifier(AbilityType::Intelligence);
    setSkillLevel(SkillType::Arcana, intel);
    setSkillLevel(SkillType::History, intel);
    setSkillLevel(SkillType::Investigation, intel);
    setSkillLevel(SkillType::Nature, intel);
    setSkillLevel(SkillType::Religion, intel);

    // Wis skills
    const auto wis = abilities->getModifier(AbilityType::Wisdom);
    setSkillLevel(SkillType::AnimalHandling, wis);
    setSkillLevel(SkillType::Insight, wis);
    setSkillLevel(SkillType::Medicine, wis);
    setSkillLevel(SkillType::Perception, wis);
    setSkillLevel(SkillType::Survival, wis);

    // Cha skills
    const auto cha = abilities->getModifier(AbilityType::Charisma);
    setSkillLevel(SkillType::Deception, cha);
    setSkillLevel(SkillType::Intimidation, cha);
    setSkillLevel(SkillType::Performance, cha);
    setSkillLevel(SkillType::Persuasion, cha);

    // passives

    auto getPassiveSkill = [&](const SkillType st)
    {
        auto mod = (skills->getSkill(st));
        auto ad = (hasAdvantage(st) ? 5 : 0);
        auto dd(hasDisadvantage(st) ? 5 : 0);

        return 10 + mod + ad - dd;
    };

    passives->perception = getPassiveSkill(SkillType::Perception);
    passives->insight = getPassiveSkill(SkillType::Insight);
    passives->investigation = getPassiveSkill(SkillType::Investigation);

    setInitiative(abilities->getModifier(AbilityType::Dexterity));
}
