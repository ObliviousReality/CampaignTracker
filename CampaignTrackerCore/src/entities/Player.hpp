#pragma once

#include "Creature.hpp"

class Player : public Creature
{
public:
    Player(const std::string name, const ClassType ct, const RaceType rt) : Creature(name), classType(ct), raceType(rt)
    {}
    const ClassType getClassType() const { return classType; }
    const RaceType getRaceType() const { return raceType; }

    const bool hasInspiration() { return inspiration; }
    void setInspiration(const bool newInsp) { inspiration = newInsp; }

private:
    ClassType classType;
    RaceType raceType;
    bool inspiration = false;
};