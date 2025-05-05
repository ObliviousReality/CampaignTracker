#pragma once

#include "entities/Creature.hpp"
#include "entities/Player.hpp"

#include "data/Condition.hpp"
#include "data/Class.hpp"
#include "data/Race.hpp"

#include <map>
#include <memory>
#include <set>

using ClassMap = std::map<ClassType, std::shared_ptr<Class>>;
using RaceMap = std::map<RaceType, std::shared_ptr<Race>>;
using ConditionMap = std::map<ConditionType, std::shared_ptr<Condition>>;

class CTCore
{
public:
    CTCore() {}
    void initalise();
    static void PrintHelloWorld();

    ClassMap getClasses() const { return classes; }
    RaceMap getRaces() const { return races; }
    ConditionMap getConditions() const { return conditions; }

    const std::string getClassString(ClassType ct) const { return classes.at(ct)->getName(); }
    const std::string getRaceString(RaceType ct) const { return races.at(ct)->getName(); }
    const std::string getConditionString(ConditionType ct) const { return conditions.at(ct)->getName();  }

    Creature * createCreature(const std::string & name);
    Player * createPlayer(const std::string & name, const ClassType classType, const RaceType raceType);

private:
    ClassMap classes;
    RaceMap races;
    ConditionMap conditions;

    std::set<Creature *> creatures;
};
