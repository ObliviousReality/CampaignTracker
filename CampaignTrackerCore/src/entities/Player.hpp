#pragma once

#include "Creature.hpp"

class Player : public Creature
{
public:
    Player(
        const std::string name,
        const ClassType ct,
        const RaceType rt,
        const std::string humanName,
        const int level,
        const std::pair<MoralityType, OrderType> alignment)
        : Creature(name, alignment), classType(ct), raceType(rt), humanPlayerName(humanName), level(level)
    {}
    const ClassType getClassType() const { return classType; }
    const RaceType getRaceType() const { return raceType; }

    const bool hasInspiration() { return inspiration; }
    void setInspiration(const bool newInsp) { inspiration = newInsp; }

    const std::string & getHumanName() const { return humanPlayerName; }

    const int getLevel() const { return level; }
    void setLevel(const int newLevel) { level = newLevel; }
    void levelUp() { level++; }

private:
    ClassType classType;
    RaceType raceType;
    std::string humanPlayerName;
    bool inspiration = false;

    int level = 1;
};