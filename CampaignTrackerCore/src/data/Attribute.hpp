#pragma once

#include <array>
#include <cmath>
#include <string>

namespace Core
{
    static int getModifier(const int skillLevel) { return static_cast<int>(std::floor((skillLevel - 10) / 2)); }
}

enum class AbilityType
{
    Strength,
    Dexterity,
    Constitution,
    Intelligence,
    Wisdom,
    Charisma,

    NUM_ABILITIES,
};

using Abilities = std::array<int, static_cast<size_t>(AbilityType::NUM_ABILITIES)>;

enum class SkillType
{
    Acrobatics,
    AnimalHandling,
    Arcana,
    Athletics,
    Deception,
    History,
    Insight,
    Intimidation,
    Investigation,
    Medicine,
    Nature,
    Perception,
    Performance,
    Persuasion,
    Religion,
    SleightOfHand,
    Stealth,
    Survival,

    NUM_SKILLS,
};

using Skills = std::array<int, static_cast<size_t>(SkillType::NUM_SKILLS)>;

enum class PassiveSkillType
{
    Perception,
    Investigation,
    Insight,

    NUM_PASSIVE_SKILLS,
};

using Passives = std::array<int, static_cast<size_t>(PassiveSkillType::NUM_PASSIVE_SKILLS)>;

namespace Core
{
    static const std::string getAbilityString(const AbilityType at)
    {
        switch (at)
        {
            case AbilityType::Strength: return "Strength";
            case AbilityType::Dexterity: return "Dexterity";
            case AbilityType::Constitution: return "Constitution";
            case AbilityType::Intelligence: return "Intelligence";
            case AbilityType::Wisdom: return "Wisdom";
            case AbilityType::Charisma: return "Charisma";
            default: return "";
        }
    }

    static const std::string getAbilityShortString(const AbilityType at)
    {
        switch (at)
        {
            case AbilityType::Strength: return "STR";
            case AbilityType::Dexterity: return "DEX";
            case AbilityType::Constitution: return "CON";
            case AbilityType::Intelligence: return "INT";
            case AbilityType::Wisdom: return "WIS";
            case AbilityType::Charisma: return "CHA";
            default: return "";
        }
    }

    static const std::string getSkillString(const SkillType st)
    {
        switch (st)
        {
            case SkillType::Acrobatics: return "Acrobatics";
            case SkillType::AnimalHandling: return "Animal Handling";
            case SkillType::Arcana: return "Arcana";
            case SkillType::Athletics: return "Athletics";
            case SkillType::Deception: return "Deception";
            case SkillType::History: return "History";
            case SkillType::Insight: return "Insight";
            case SkillType::Intimidation: return "Intimidation";
            case SkillType::Investigation: return "Investigation";
            case SkillType::Medicine: return "Medicine";
            case SkillType::Nature: return "Nature";
            case SkillType::Perception: return "Perception";
            case SkillType::Performance: return "Performance";
            case SkillType::Persuasion: return "Persuasion";
            case SkillType::Religion: return "Religion";
            case SkillType::SleightOfHand: return "Sleight of Hand";
            case SkillType::Stealth: return "Stealth";
            case SkillType::Survival: return "Survival";
            default: return "";
        }
    }
};
