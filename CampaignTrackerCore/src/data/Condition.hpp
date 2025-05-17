#pragma once
#include <string>

enum class ConditionType
{
    Blinded,
    Charmed,
    Deafened,
    Frightened,
    Grappled,
    Incapacitated,
    Invisible,
    Paralysed,
    Petrified,
    Poisoned,
    Prone,
    Restrained,
    Stunned,
    Unconscious,
    Exhaustion,

    NUM_CONDITIONS,
};

namespace Core
{
    static const std::string getConditionString(const ConditionType ct)
    {
        switch (ct)
        {
            case ConditionType::Blinded: return "Blinded";
            case ConditionType::Charmed: return "Charmed";
            case ConditionType::Deafened: return "Deafened";
            case ConditionType::Frightened: return "Frightened";
            case ConditionType::Grappled: return "Grappled";
            case ConditionType::Incapacitated: return "Incapacitated";
            case ConditionType::Invisible: return "Invisible";
            case ConditionType::Paralysed: return "Paralysed";
            case ConditionType::Petrified: return "Petrified";
            case ConditionType::Poisoned: return "Poisoned";
            case ConditionType::Prone: return "Prone";
            case ConditionType::Restrained: return "Restrained";
            case ConditionType::Stunned: return "Stunned";
            case ConditionType::Unconscious: return "Unconscious";
            case ConditionType::Exhaustion: return "Exhaustion";
            default: return "";
        }
    }
};
