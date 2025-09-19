#pragma once

#include "Entity.hpp"

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
#include <vector>

enum class CreatureType
{
    Player,
    NPC,
    Monster,

    NUM_CREATURES,
};

class Creature : public Entity
{
public:
    Creature(const EntityId newId, const EntityType t, CreatureType ct) : Entity(newId, t), creatureType(ct) {}

    void setName(const std::string & newName) { name = newName; }
    const std::string & getName() const { return name; }

    // not set, comes from constructor
    CreatureType getCreatureType() const { return creatureType; }

    void setHitPoints(int newHP) { hitPoints = newHP; }
    int getHitPoints() const { return hitPoints; }

    void setMaxHitPoints(int newMaxHP) { hitPointsMax = newMaxHP; }
    int getHitPointsMax() const { return hitPointsMax; }

    void setTempHitPoint(int newTempHP) { tempHitPoints = newTempHP; }
    int getTempHitPoints() const { return tempHitPoints; }

    // no set as this is calculated
    int getTotalHitPoints() const { return hitPoints + tempHitPoints; }

    void setAC(int newAC) { armourClass = newAC; }
    int getAC() const { return armourClass; }

    void setSpeed(int newSpeed) { speed = newSpeed; }
    int getSpeed() const { return speed; }

    void setSpeedModifier(int speedMod) { speed += speedMod; }
    // no get

    void setInitiative(int newInitiative) { initiative = newInitiative; }
    int getInitiative() const { return initiative; }

    void setProficiency(int newProf) { proficiency = newProf; }
    int getProficiency() const { return proficiency; }

    void setAbility(AbilityType at, int val) { abilities[static_cast<int>(at)] = val; }
    int getAbility(AbilityType at) const { return abilities.at(static_cast<int>(at)); }

    void setAbilities(const Abilities & newAbilities) { abilities = newAbilities; }
    const Abilities & getAbilities() { return abilities; }

    void setSkill(SkillType st, int val) { skills[static_cast<int>(st)] = val; }
    int getSkill(SkillType st) const { return skills.at(static_cast<int>(st)); }

    void setSkills(const Skills & newSkills) { skills = newSkills; }
    const Skills & getSkills() const { return skills; }

    void setPassiveSkill(PassiveSkillType pst, int val) { passives[static_cast<int>(pst)] = val; }
    int getPassiveSkill(PassiveSkillType pst) const { return passives[static_cast<int>(pst)]; }

    void setPassives(const Passives & newPassives) { passives = newPassives; }
    const Passives & getPassives() const { return passives; }

    bool hasAdvantage(AbilityType at) { return abilityAdvantages.find(at) != abilityAdvantages.end(); }
    bool hasAdvantage(SkillType st) { return skillAdvantages.find(st) != skillAdvantages.end(); }
    bool hasInitiativeAdvantage() const { return initiativeAdvantage; }

    bool hasDisadvantage(AbilityType at) { return abilityDisadvantages.find(at) != abilityDisadvantages.end(); }
    bool hasDisadvantage(SkillType st) const { return skillDisadvantages.find(st) != skillDisadvantages.end(); }
    bool hasInitiativeDisadvantage() const { return initiativeDisadvantage; }

    void setAdvantage(AbilityType at, bool val)
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

    void setAdvantage(SkillType st, bool val)
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
    void setInitiativeAdvantage(bool val) { initiativeAdvantage = val; }

    void setAdvantages(const std::set<AbilityType> & newAbilities) { abilityAdvantages = newAbilities; }
    const std::set<AbilityType> & getAbilityAdvantages() const { return abilityAdvantages; }
    void setAdvantages(const std::set<SkillType> & newSkills) { skillAdvantages = newSkills; }
    const std::set<SkillType> & getSkillAdvantages() const { return skillAdvantages; }

    void setDisadvantage(AbilityType at, bool val)
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

    void setDisadvantage(SkillType st, bool val)
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
    void setInitiativeDisadvantage(bool val) { initiativeDisadvantage = val; }

    void setDisadvantages(const std::set<AbilityType> & newAbilities) { abilityDisadvantages = newAbilities; }
    const std::set<AbilityType> & getAbilityDisadvantages() const { return abilityDisadvantages; }
    void setDisadvantages(const std::set<SkillType> & newSkills) { skillDisadvantages = newSkills; }
    const std::set<SkillType> & getSkillDisadvantages() const { return skillDisadvantages; }

    void addCondition(ConditionType ct) { conditions.emplace(ct); }
    void removeCondition(ConditionType ct) { conditions.erase(ct); }
    bool hasCondition(ConditionType ct) { return conditions.find(ct) != conditions.end(); }

    void setConditions(const std::set<ConditionType> & newConditions) { conditions = newConditions; }
    const std::set<ConditionType> & getConditions() const { return conditions; }

    void addImmunity(ConditionType ct) { conditionImmunities.emplace(ct); }
    void removeImmunity(ConditionType ct) { conditionImmunities.erase(ct); }
    bool hasImmunity(ConditionType ct) { return conditionImmunities.find(ct) != conditionImmunities.end(); }

    void setImmunities(const std::set<ConditionType> & newImmunities) { conditionImmunities = newImmunities; }
    const std::set<ConditionType> & getConditionImmunities() const { return conditionImmunities; }

    void addImmunity(DamageType dt) { damageTypeImmunities.emplace(dt); }
    void removeImmunity(DamageType dt) { damageTypeImmunities.erase(dt); }
    bool hasImmunity(DamageType dt) { return damageTypeImmunities.find(dt) != damageTypeImmunities.end(); }

    void setImmunities(const std::set<DamageType> & newImmunities) { damageTypeImmunities = newImmunities; }
    const std::set<DamageType> & getDamageImmunities() const { return damageTypeImmunities; }

    void addResistance(DamageType dt) { resistances.emplace(dt); }
    void removeResistance(DamageType dt) { resistances.erase(dt); }
    bool hasResistance(DamageType dt) { return resistances.find(dt) != resistances.end(); }

    void setResistances(const std::set<DamageType> & newResistances) { resistances = newResistances; }
    const std::set<DamageType> & getResistances() const { return resistances; }

    void addVulnerability(DamageType dt) { vulnerabilities.emplace(dt); }
    void removeVulnerability(DamageType dt) { vulnerabilities.erase(dt); }
    bool hasVulnerability(DamageType dt) { return vulnerabilities.find(dt) != vulnerabilities.end(); }

    void setVulnerabilities(const std::set<DamageType> & newVulnerabilities) { vulnerabilities = newVulnerabilities; }
    const std::set<DamageType> & getVulnerabilities() const { return vulnerabilities; }

    void addSense(SenseType st) { senses.emplace(st); }
    void removeSense(SenseType st) { senses.erase(st); }
    bool hasSense(SenseType st) { return senses.find(st) != senses.end(); }

    void setSenses(const std::set<SenseType> & newSenses) { senses = newSenses; }
    const std::set<SenseType> & getSenses() const { return senses; }

    void setAlignment(const std::pair<MoralityType, OrderType> & alignment)
    {
        setAlignment(alignment.first, alignment.second);
    }
    void setAlignment(MoralityType newMorality, OrderType newOrder)
    {
        morality = newMorality;
        order = newOrder;
    }
    std::pair<MoralityType, OrderType> getAlignment() const { return { morality, order }; }

    void setTaggedSkill(SkillType st, int tagLevel = 1) { taggedSkills[st] = tagLevel; }
    void setTaggedSkills(const std::vector<SkillType> & skills, int tagLevel = 1);
    int getTaggedSkillLevel(SkillType st) const { return taggedSkills.count(st) ? taggedSkills.at(st) : 0; }

    int getSkillModifier(SkillType st) const
    {
        return Core::getModifier(skills[static_cast<int>(st)] + (getProficiency() * getTaggedSkillLevel(st)));
    }

    void setTaggedSavingThrows(const std::vector<AbilityType> & savingThrows, const int tagLevel = 1);
    void setTaggedSavingThrow(AbilityType at, int tagLevel = 1) { taggedSavingThrows[at] = tagLevel; }
    int getTaggedSavingThrowLevel(AbilityType at) const
    {
        return taggedSavingThrows.count(at) ? taggedSavingThrows.at(at) : 0;
    }

    int getSavingThrowModifier(AbilityType at)
    {
        return Core::getModifier(abilities[static_cast<int>(at)]) + (getProficiency() * getTaggedSavingThrowLevel(at));
    }

    int getModifier(AbilityType at) { return getModifierInternal(abilities.at(static_cast<int>(at))); }
    int getModifier(SkillType at) { return getModifierInternal(skills[static_cast<int>(at)]); }
    int getModifier(PassiveSkillType at) { return getModifierInternal(passives[static_cast<int>(at)]); }

    virtual void generateSkills();

private:
    int getModifierInternal(int value) { return Core::getModifier(value); }

    CreatureType creatureType;
    std::string name;

    int hitPoints = 0;
    int hitPointsMax = 0;
    int armourClass = 0;
    int speed = 30;
    int initiative = 0;
    int proficiency = 0;
    int tempHitPoints = 0;

    Abilities abilities = {};
    Skills skills = {};
    Passives passives = {};

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
    std::map<AbilityType, int> taggedSavingThrows;
};
