#pragma once

#include <string>

enum class SenseType
{
    Blindsight,
    Darkvision,
    Tremorsense,
    Truesight,

    NUM_SENSES,
};

class Sense
{
public:
    Sense(const std::string name) : name(name) {}

    const std::string & getName() { return name; }

private:
    std::string name;
};