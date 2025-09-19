#pragma once

#include "entities/Entity.hpp"

#include "data/Attribute.hpp"

#include <list>
#include <string>

class Template : public Entity
{
public:
    Template(EntityId id, EntityType type) : Entity(id, type) {}

    void setName(const std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

    void setSpeed(const int newSpeed) { speed = newSpeed; }
    const int getSpeed() const { return speed; }

    void setAbilities(const Abilities & newAbilities) { abilities = newAbilities; }
    const Abilities & getAbilities() const { return abilities; }

    void setMaxHitPoints(const int newHP) { hitPointsMax = newHP; }
    const int getHitPointsMax() const { return hitPointsMax; }

    void setAC(const int newAC) { armourClass = newAC; }
    const int getAC() const { return armourClass; }

    void addCondition(const ConditionType ct) { conditions.emplace(ct); }

    void addImmunity(const ConditionType ct) { conditionImmunities.emplace(ct); }

    void addImmunity(const DamageType dt) { damageTypeImmunities.emplace(dt); }

    void addResistance(const DamageType dt) { resistances.emplace(dt); }

    void addVulnerability(const DamageType dt) { vulnerabilities.emplace(dt); }

    void addSense(const SenseType st) { senses.emplace(st); }

    const std::set<SkillType> & getSkillAdvantages() const { return skillAdvantages; }
    const std::set<AbilityType> & getAbilityAdvantages() const { return abilityAdvantages; }

    const std::set<SkillType> & getSkillDisadvantages() const { return skillDisadvantages; }
    const std::set<AbilityType> & getAbilityDisadvantages() const { return abilityDisadvantages; }

    const std::set<ConditionType> & getConditions() const { return conditions; }

    const std::set<ConditionType> & getConditionImmunities() const { return conditionImmunities; }
    const std::set<DamageType> & getDamageTypeImmunities() const { return damageTypeImmunities; }

    const std::set<DamageType> & getResistances() const { return resistances; }
    const std::set<DamageType> & getVulnerabilities() const { return vulnerabilities; }

    const std::set<SenseType> & getSenses() const { return senses; }

    const std::pair<MoralityType, OrderType> getAlignment() const { return { morality, order }; }

    void setAlignment(const MoralityType newMorality, const OrderType newOrder)
    {
        morality = newMorality;
        order = newOrder;
    }

private:
    std::string name;
    int hitPointsMax = 0;
    int armourClass = 0;
    int speed = 30;

    Abilities abilities;

    std::set<SkillType> skillAdvantages;
    std::set<SkillType> skillDisadvantages;
    std::set<AbilityType> abilityAdvantages;
    std::set<AbilityType> abilityDisadvantages;

    std::set<ConditionType> conditions;
    std::set<ConditionType> conditionImmunities;

    std::set<DamageType> damageTypeImmunities;
    std::set<DamageType> resistances;
    std::set<DamageType> vulnerabilities;

    std::set<SenseType> senses;

    MoralityType morality;
    OrderType order;
};
