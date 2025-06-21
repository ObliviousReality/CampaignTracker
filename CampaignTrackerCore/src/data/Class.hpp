#pragma once
#include <string>

enum class ClassType : unsigned int
{
    None,
    Barbarian,
    Bard,
    Cleric,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Rogue,
    Sorcerer,
    Warlock,
    Wizard,
    Artificer,
    NUM_CLASSES,
};

namespace Core
{
    static const std::string getClassString(const ClassType ct)
    {
        switch (ct)
        {
            case ClassType::None: return "None";
            case ClassType::Barbarian: return "Barbarian";
            case ClassType::Bard: return "Bard";
            case ClassType::Cleric: return "Cleric";
            case ClassType::Druid: return "Druid";
            case ClassType::Fighter: return "Fighter";
            case ClassType::Monk: return "Monk";
            case ClassType::Paladin: return "Paladin";
            case ClassType::Ranger: return "Ranger";
            case ClassType::Rogue: return "Rogue";
            case ClassType::Sorcerer: return "Sorcerer";
            case ClassType::Warlock: return "Warlock";
            case ClassType::Wizard: return "Wizard";
            case ClassType::Artificer: return "Artificer";
            default: return "";
        }
    }
};
