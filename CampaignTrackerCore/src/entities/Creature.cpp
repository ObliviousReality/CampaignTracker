#include "Creature.hpp"

Creature::Creature(const std::string name, const std::pair<MoralityType, OrderType> alignment) : name(name)
{
    abilities = std::make_unique<Abilities>();
    skills = std::make_unique<Skills>();
    savingThrows = std::make_unique<Abilities>();
    passives = std::make_unique<PassiveSkills>();

    morality = alignment.first;
    order = alignment.second;
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
}
