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
