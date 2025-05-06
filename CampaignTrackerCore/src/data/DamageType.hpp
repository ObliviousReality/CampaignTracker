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

private:
    std::string name;
};