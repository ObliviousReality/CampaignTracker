#pragma once

#include "Template.hpp"

#include "data/Alignment.hpp"
#include "data/Attribute.hpp"
#include "data/Condition.hpp"
#include "data/DamageType.hpp"
#include "data/Sense.hpp"

#include <array>
#include <map>
#include <memory>
#include <set>
#include <vector>

class CreatureTemplate : public Template
{
public:
    CreatureTemplate(TemplateId id, TemplateType type) : Template(id, type) {}

    const int getHitPointsMax() const { return hitPointsMax; }
    void setMaxHitPoints(const int newMaxHP) { hitPointsMax = newMaxHP; }

    const int getAC() const { return armourClass; }
    void setAC(const int newAC) { armourClass = newAC; }

    const AbilityArray & const getAbilities() const { return abilities; }
    void setAbilities(const AbilityArray & _abilities) { abilities = _abilities; }

    const bool getInitiativeAdvantage() { return initiativeAdvantage; }
    void setInitiativeAdvantage(const bool val) { initiativeAdvantage = val; }

    const bool getInitiativeDisadvantage() { return initiativeDisadvantage; }
    void setInitiativeDisadvantage(const bool val) { initiativeDisadvantage = val; }

    const std::set<SkillType> & getSkillAdvantages() const { return skillAdvantages; }
    const std::set<AbilityType> & getAbilityAdvantages() const { return abilityAdvantages; }
    void setAdvantage(const AbilityType at) { abilityAdvantages.emplace(at); }
    void setAdvantage(const SkillType st) { skillAdvantages.emplace(st); }

    const std::set<SkillType> & getSkillDisadvantages() const { return skillDisadvantages; }
    const std::set<AbilityType> & getAbilityDisadvantages() const { return abilityDisadvantages; }
    void setDisadvantage(const AbilityType at) { abilityDisadvantages.emplace(at); }
    void setDisadvantage(const SkillType st) { skillDisadvantages.emplace(st); }

    const std::set<ConditionType> & getConditionImmunities() const { return conditionImmunities; }
    const std::set<DamageType> & getDamageTypeImmunities() const { return damageTypeImmunities; }
    void setImmunity(const ConditionType ct) { conditionImmunities.emplace(ct); }
    void setImmunity(const DamageType dt) { damageTypeImmunities.emplace(dt); }

    const std::set<DamageType> & getResistances() const { return resistances; }
    void setResistance(const DamageType dt) { resistances.emplace(dt); }

    const std::set<DamageType> & getVulnerabilities() const { return vulnerabilities; }
    void setVulnerability(const DamageType dt) { vulnerabilities.emplace(dt); }

    const std::set<SenseType> & getSenses() const { return senses; }
    void setSense(const SenseType st) { senses.emplace(st); }

    const std::pair<MoralityType, OrderType> getAlignment() const { return { morality, order }; }
    void setAlignment(const MoralityType newMorality, const OrderType newOrder)
    {
        morality = newMorality;
        order = newOrder;
    }

    const std::map<SkillType, int> & getTaggedSkills() const { return taggedSkills; }
    void setTaggedSkills(const std::map<SkillType, int> & skills) { taggedSkills = skills; }

    const std::map<AbilityType, int> & getTaggedSavingThrows() const { return taggedSavingThrows; }
    void setTaggedSavingThrows(const std::map<AbilityType, int> & savingThrows) { taggedSavingThrows = savingThrows; };

private:
    int hitPointsMax = 0;
    int armourClass = 0;

    AbilityArray abilities;

    std::set<SkillType> skillAdvantages;
    std::set<SkillType> skillDisadvantages;
    std::set<AbilityType> abilityAdvantages;
    std::set<AbilityType> abilityDisadvantages;
    bool initiativeAdvantage = false;
    bool initiativeDisadvantage = false;

    std::set<ConditionType> conditionImmunities;

    std::set<DamageType> damageTypeImmunities;
    std::set<DamageType> resistances;
    std::set<DamageType> vulnerabilities;

    std::set<SenseType> senses;

    MoralityType morality = {};
    OrderType order = {};

    std::map<SkillType, int> taggedSkills;
    std::map<AbilityType, int> taggedSavingThrows;
};