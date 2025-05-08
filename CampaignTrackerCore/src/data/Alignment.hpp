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

class Alignment
{
public:
    Alignment(const std::string name) : name(name) {}

    const std::string & getName() const { return name; }

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
        return Alignment::getOrderString(alignment.second) + " " + Alignment::getMoralityString(alignment.first);
    }

private:
    std::string name;
};

class Morality : public Alignment
{
public:
    Morality(const std::string name) : Alignment(name) {}


};

class Order : public Alignment
{
public:
    Order(const std::string name) : Alignment(name) {}


};
