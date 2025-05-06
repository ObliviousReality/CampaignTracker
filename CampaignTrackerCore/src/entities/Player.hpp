#pragma once

#include "Creature.hpp"

class Player : public Creature
{
public:
    Player(const std::string name, const ClassType ct, const RaceType rt, const std::string humanName)
        : Creature(name), classType(ct), raceType(rt), humanPlayerName(humanName)
    {}
    const ClassType getClassType() const { return classType; }
    const RaceType getRaceType() const { return raceType; }

    const bool hasInspiration() { return inspiration; }
    void setInspiration(const bool newInsp) { inspiration = newInsp; }

    const std::string & getHumanName() const { return humanPlayerName; }

private:
    ClassType classType;
    RaceType raceType;
    std::string humanPlayerName;
    bool inspiration = false;
};