#pragma once
#include <string>

enum class ClassType : unsigned int
{
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

class Class
{
public:
    Class(const std::string name) : name(name) {}

    const std::string & getName() { return name; }

private:
    std::string name;
};