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
using MoralityMap = std::map<MoralityType, std::shared_ptr<Morality>>;
using OrderMap = std::map<OrderType, std::shared_ptr<Order>>;

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
    const MoralityMap & getMoralities() const { return moralities; }
    const OrderMap & getOrders() const { return orders; }

    const std::string & getClassString(const ClassType ct) const { return classes.at(ct)->getName(); }
    const std::string & getRaceString(const RaceType ct) const { return races.at(ct)->getName(); }
    const std::string & getConditionString(const ConditionType ct) const { return conditions.at(ct)->getName(); }
    const std::string & getDamageTypeString(const DamageType dt) const { return damageTypes.at(dt)->getName(); }
    const std::string & getSenseString(const SenseType st) const { return senses.at(st)->getName(); }
    const std::string getAlignmentString(std::pair<MoralityType, OrderType> alignment) const;
    const std::string getAlignmentString(const MoralityType mt, const OrderType ot) const;

    Creature * createCreature(const std::string & name);
    Player * createPlayer(
        const std::string & name,
        const ClassType classType,
        const RaceType raceType,
        const std::string & human,
        const int level,
        const std::pair<MoralityType, OrderType> alignment);

private:
    ClassMap classes;
    RaceMap races;
    ConditionMap conditions;
    DamageTypeMap damageTypes;
    SenseMap senses;
    MoralityMap moralities;
    OrderMap orders;

    std::set<Creature *> creatures;
};
