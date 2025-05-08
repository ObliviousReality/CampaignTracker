#pragma once

#include <string>

enum class DamageType
{
    Acid,
    Bludgeoning,
    Cold,
    Fire,
    Force,
    Lightning,
    Necrotic,
    Piercing,
    Poison,
    Psychic,
    Radiant,
    Slashing,
    Thunder,

    NUM_DAMAGE_TYPES,
};

class DamageTypeObj
{
public:
    DamageTypeObj(const std::string name) : name(name) {}

    const std::string & getName() const { return name; }

    static const std::string getDamageTypeString(const DamageType dt)
    {
        switch (dt)
        {
            case DamageType::Acid: return "Acid";
            case DamageType::Bludgeoning: return "Bludgeoning";
            case DamageType::Cold: return "Cold";
            case DamageType::Fire: return "Fire";
            case DamageType::Force: return "Force";
            case DamageType::Lightning: return "Lightning";
            case DamageType::Necrotic: return "Necrotic";
            case DamageType::Piercing: return "Piercing";
            case DamageType::Poison: return "Poison";
            case DamageType::Psychic: return "Psychic";
            case DamageType::Radiant: return "Radiant";
            case DamageType::Slashing: return "Slashing";
            case DamageType::Thunder: return "Thunder";
            default: return "";
        }
    }

private:
    std::string name;
};