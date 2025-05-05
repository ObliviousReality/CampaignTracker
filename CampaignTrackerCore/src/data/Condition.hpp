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

class Condition
{
public:
    Condition(std::string name) : name(name) {}

    const std::string getName() const { return name; }

private:
    std::string name;
};