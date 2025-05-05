#pragma once
#include "data/Class.hpp"
#include "data/Race.hpp"

#include <string>

class Creature
{
public:
    Creature(const std::string name, const ClassType classType, const RaceType raceType)
        : name(name), classType(classType), raceType(raceType)
    {}
    
    const std::string getName() const { return name; }
    const ClassType getClassType() const { return classType; }
    const RaceType getRaceType() const { return raceType; }

private:
public:
private:
    std::string name;
    ClassType classType;
    RaceType raceType;
};