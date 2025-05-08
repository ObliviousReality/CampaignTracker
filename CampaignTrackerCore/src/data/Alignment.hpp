#pragma once

#include <string>

enum class MoralityType
{
    None,
    Good,
    Neutral,
    Evil,

    NUM_MORALITLIES,
};

enum class OrderType
{
    None,
    Lawful,
    Neutral,
    Chaotic,

    NUM_ORDERS,
};

namespace Core
{
    static const std::string getOrderString(const OrderType ot)
    {
        switch (ot)
        {
            case OrderType::None: return "None";
            case OrderType::Lawful: return "Lawful";
            case OrderType::Neutral: return "Neutral";
            case OrderType::Chaotic: return "Chaotic";
            default: return "";
        }
    }

    static const std::string getMoralityString(const MoralityType mt)
    {
        switch (mt)
        {
            case MoralityType::None: return "None";
            case MoralityType::Good: return "Good";
            case MoralityType::Neutral: return "Neutral";
            case MoralityType::Evil: return "Evil";
            default: return "";
        }
    }

    static const std::string getAlignmentString(const std::pair<MoralityType, const OrderType> & alignment)
    {
        return Core::getOrderString(alignment.second) + " " + Core::getMoralityString(alignment.first);
    }
};
