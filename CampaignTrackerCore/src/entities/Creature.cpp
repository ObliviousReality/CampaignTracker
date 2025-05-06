#include "Creature.hpp"

Creature::Creature(const std::string name) : name(name)
{
    abilities = std::make_unique<Abilities>();
    skills = std::make_unique<Skills>();
    savingThrows = std::make_unique<Abilities>();
    passives = std::make_unique<PassiveSkills>();
}
