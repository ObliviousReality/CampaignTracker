#pragma once

#include "Class.hpp"

#include "core/Dice.hpp"

namespace Core
{
    static const Dice getClassHPDice(const ClassType ct)
    {
        switch (ct)
        {
            case ClassType::Barbarian: return Dice::D12;
            case ClassType::Bard: return Dice::D8;
            case ClassType::Cleric: return Dice::D8;
            case ClassType::Druid: return Dice::D8;
            case ClassType::Fighter: return Dice::D10;
            case ClassType::Monk: return Dice::D8;
            case ClassType::Paladin: return Dice::D10;
            case ClassType::Ranger: return Dice::D10;
            case ClassType::Rogue: return Dice::D8;
            case ClassType::Sorcerer: return Dice::D6;
            case ClassType::Warlock: return Dice::D8;
            case ClassType::Wizard: return Dice::D6;
            case ClassType::Artificer: return Dice::D8;
            default: return Dice::D8;
        }
    }
};
