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

    static const std::string getSenseString(const SenseType st)
    {
        switch (st)
        {
            case SenseType::Blindsight: return "Blindsight";
            case SenseType::Darkvision: return "Darkvision";
            case SenseType::Tremorsense: return "Tremorsense";
            case SenseType::Truesight: return "Truesight";
            default: return "";
        }
    }

private:
    std::string name;
};