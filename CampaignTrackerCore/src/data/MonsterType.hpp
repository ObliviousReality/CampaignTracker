#pragma once

#include <string>

enum class MonsterType
{
	Abberation,
	Beast,
	Celestial,
	Construct,
	Dragon,
	Elemental,
	Fey,
	Fiend,
	Giant,
	Humanoid,
	Monstrosity,
	Ooze,
	Plant,
	Undead,
};

namespace Core
{
    static const std::string getMonsterTypeString(const MonsterType ct)
    {
        switch (ct)
        {
            case MonsterType::Abberation: return "Abberation";
            case MonsterType::Beast: return "Beast";
            case MonsterType::Celestial: return "Celestial";
            case MonsterType::Construct: return "Construct";
            case MonsterType::Dragon: return "Dragon";
            case MonsterType::Elemental: return "Elemental";
            case MonsterType::Fey: return "Fey";
            case MonsterType::Fiend: return "Fiend";
            case MonsterType::Giant: return "Giant";
            case MonsterType::Humanoid: return "Humanoid";
            case MonsterType::Monstrosity: return "Monstrosity";
            case MonsterType::Ooze: return "Ooze";
            case MonsterType::Plant: return "Plant";
            case MonsterType::Undead: return "Undead";
            default: return "";
        }
    }
}