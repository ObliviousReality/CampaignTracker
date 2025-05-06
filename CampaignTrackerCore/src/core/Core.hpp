#pragma once

#include "entities/Creature.hpp"
#include "entities/Player.hpp"

#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Senses.hpp"

#include <map>
#include <memory>
#include <set>

using ClassMap = std::map<ClassType, std::shared_ptr<Class>>;
using RaceMap = std::map<RaceType, std::shared_ptr<Race>>;
using ConditionMap = std::map<ConditionType, std::shared_ptr<Condition>>;
using DamageTypeMap = std::map<DamageType, std::shared_ptr<DamageTypeObj>>;
using SenseMap = std::map<SenseType, std::shared_ptr<Sense>>;

class CTCore
{
public:
    CTCore() {}
    void initalise();
    static void PrintHelloWorld();

    const ClassMap & getClasses() const { return classes; }
    const RaceMap & getRaces() const { return races; }
    const ConditionMap & getConditions() const { return conditions; }
    const DamageTypeMap & getDamageTypes() const { return damageTypes; }
    const SenseMap & getSenses() const { return senses; }

    const std::string & getClassString(const ClassType ct) const { return classes.at(ct)->getName(); }
    const std::string & getRaceString(const RaceType ct) const { return races.at(ct)->getName(); }
    const std::string & getConditionString(const ConditionType ct) const { return conditions.at(ct)->getName(); }
    const std::string & getDamageTypeString(const DamageType dt) const { return damageTypes.at(dt)->getName(); }
    const std::string & getSenseString(const SenseType st) const { return senses.at(st)->getName(); }

    Creature * createCreature(const std::string & name);
    Player * createPlayer(
        const std::string & name,
        const ClassType classType,
        const RaceType raceType,
        const std::string & human,
        const int level);

private:
    ClassMap classes;
    RaceMap races;
    ConditionMap conditions;
    DamageTypeMap damageTypes;
    SenseMap senses;

    std::set<Creature *> creatures;
};
