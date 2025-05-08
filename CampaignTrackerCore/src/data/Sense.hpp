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

namespace Core
{
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
};
