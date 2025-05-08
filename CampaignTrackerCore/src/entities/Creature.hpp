#pragma once

#include "data/Alignment.hpp"
#include "data/Attribute.hpp"
#include "data/Class.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Race.hpp"
#include "data/Sense.hpp"

#include <map>
#include <memory>
#include <set>
#include <string>

class Creature
{
public:
    Creature(const std::string name, const std::pair<MoralityType, OrderType> alignment);

    const std::string getName() const { return name; }

    const int getHitPoints() const { return hitPoints; }
    const int getHitPointsMax() const { return hitPointsMax; }
    const int getTempHitPoints() const { return tempHitPoints; }
    const int getTotalHitPoints() const { return hitPoints + tempHitPoints; }
    const int getAC() const { return armourClass; }
    const int getSpeed() const { return speed; }
    const int getInitiative() const { return initiative; }
    const int getProficiency() const { return proficiency; }

    void setHitPoints(const int newHP) { hitPoints = newHP; }
    void setMaxHitPoints(const int newMaxHP) { hitPointsMax = newMaxHP; }
    void setTempHitPoint(const int newTempHP) { tempHitPoints = newTempHP; }
    void setAC(const int newAC) { armourClass = newAC; }
    void setSpeed(const int newSpeed) { speed = newSpeed; }
    void setInitiative(const int newInitiative) { initiative = newInitiative; }
    void setProficiency(const int newProf) { proficiency = newProf; }

    const int getAbility(const AbilityType at) const { return abilities->getAbility(at); }
    const int getSavingThrow(const AbilityType st) const { return abilities->getAbility(st); }
    const int getSkill(const SkillType st) const { return skills->getSkill(st); }
    const int getPassiveAbility(const PassiveSkillType pst) { return passives->getPassiveSkill(pst); }

    void setAbility(const AbilityType at, const int val) const { return abilities->setAbility(at, val); }
    void setSavingThrow(const AbilityType st, const int val) const { return abilities->setAbility(st, val); }
    void setSkill(const SkillType st, const int val) const { return skills->setSkill(st, val); }
    void setPassiveAbility(const PassiveSkillType pst, const int val) { return passives->setPassiveSkill(pst, val); }

    const bool hasAdvantage(const AbilityType at) { return abilityAdvantages.find(at) != abilityAdvantages.end(); }
    const bool hasAdvantage(const SkillType st) { return skillAdvantages.find(st) != skillAdvantages.end(); }
    const bool hasInitiativeAdvantage() { return initiativeAdvantage; }

    const bool hasDisadvantage(const AbilityType at)
    {
        return abilityDisadvantages.find(at) != abilityDisadvantages.end();
    }
    const bool hasDisadvantage(const SkillType st) { return skillDisadvantages.find(st) != skillDisadvantages.end(); }
    const bool hasInitiativeDisadvantage() { return initiativeDisadvantage; }

    void setAdvantage(const AbilityType at, const bool val)
    {
        if (val)
        {
            abilityAdvantages.emplace(at);
        }
        else
        {
            abilityAdvantages.erase(at);
        }
    }

    void setAdvantage(const SkillType st, const bool val)
    {
        if (val)
        {
            skillAdvantages.emplace(st);
        }
        else
        {
            skillAdvantages.erase(st);
        }
    }
    void setInitiativeAdvantage(const bool val) { initiativeAdvantage = val; }

    void setDisadvantage(const AbilityType at, const bool val)
    {
        if (val)
        {
            abilityDisadvantages.emplace(at);
        }
        else
        {
            abilityDisadvantages.erase(at);
        }
    }

    void setDisadvantage(const SkillType st, const bool val)
    {
        if (val)
        {
            skillDisadvantages.emplace(st);
        }
        else
        {
            skillDisadvantages.erase(st);
        }
    }
    void setInitiativeDisadvantage(const bool val) { initiativeDisadvantage = val; }

    void addCondition(const ConditionType ct) { conditions.emplace(ct); }
    void removeCondition(const ConditionType ct) { conditions.erase(ct); }
    const bool hasCondition(const ConditionType ct) { return conditions.find(ct) != conditions.end(); }

    void addImmunity(const ConditionType ct) { conditionImmunities.emplace(ct); }
    void removeImmunity(const ConditionType ct) { conditionImmunities.erase(ct); }
    const bool hasImmunity(const ConditionType ct) { return conditionImmunities.find(ct) != conditionImmunities.end(); }

    void addImmunity(const DamageType dt) { damageTypeImmunities.emplace(dt); }
    void removeImmunity(const DamageType dt) { damageTypeImmunities.erase(dt); }
    const bool hasImmunity(const DamageType dt) { return damageTypeImmunities.find(dt) != damageTypeImmunities.end(); }

    void addResistance(const DamageType dt) { resistances.emplace(dt); }
    void removeResistance(const DamageType dt) { resistances.erase(dt); }
    const bool hasResistance(const DamageType dt) { return resistances.find(dt) != resistances.end(); }

    void addVulnerability(const DamageType dt) { vulnerabilities.emplace(dt); }
    void removeVulnerability(const DamageType dt) { vulnerabilities.erase(dt); }
    const bool hasVulnerability(const DamageType dt) { return vulnerabilities.find(dt) != vulnerabilities.end(); }

    void addSense(const SenseType st) { senses.emplace(st); }
    void removeSense(const SenseType st) { senses.erase(st); }
    const bool hasSense(const SenseType st) { return senses.find(st) != senses.end(); }

    const Abilities * const getAbilities() const { return abilities.get(); }
    const Abilities * const getSavingThrows() const { return savingThrows.get(); }
    const Skills * const getSkills() const { return skills.get(); }
    const PassiveSkills * const getPassives() const { return passives.get(); }

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

    void setTaggedSkill(const SkillType st, const int tagLevel = 1) { taggedSkills[st] = tagLevel; }
    const int getTaggedSkillLevel(const SkillType st) const { return taggedSkills.count(st) ? taggedSkills.at(st) : 0; }

    const int getSkillModifier(const SkillType st) const
    {
        return skills->getModifier(st) + (getProficiency() * getTaggedSkillLevel(st));
    }

    void generateSkills();

private:
    std::string name;

    int hitPoints = 0;
    int hitPointsMax = 0;
    int armourClass = 0;
    int speed = 30;
    int initiative = 0;
    int proficiency = 0;
    int tempHitPoints = 0;

    std::unique_ptr<Abilities> abilities;
    std::unique_ptr<Abilities> savingThrows;
    std::unique_ptr<Skills> skills;
    std::unique_ptr<PassiveSkills> passives;

    std::set<SkillType> skillAdvantages;
    std::set<SkillType> skillDisadvantages;
    std::set<AbilityType> abilityAdvantages;
    std::set<AbilityType> abilityDisadvantages;
    bool initiativeAdvantage = false;
    bool initiativeDisadvantage = false;

    std::set<ConditionType> conditions;
    std::set<ConditionType> conditionImmunities;

    std::set<DamageType> damageTypeImmunities;
    std::set<DamageType> resistances;
    std::set<DamageType> vulnerabilities;

    std::set<SenseType> senses;

    MoralityType morality;
    OrderType order;

    std::map<SkillType, int> taggedSkills;
};