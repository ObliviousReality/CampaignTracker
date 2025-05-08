#pragma once

#include <string>

enum class AbilityType
{
    Strength,
    Dexterity,
    Constitution,
    Intelligence,
    Wisdom,
    Charisma,

    NUM_ABILITIES,
};

enum class SkillType
{
    Acrobatics,
    AnimalHandling,
    Arcana,
    Athletics,
    Deception,
    History,
    Insight,
    Intimidation,
    Investigation,
    Medicine,
    Nature,
    Perception,
    Performance,
    Persuasion,
    Religion,
    SleightOfHand,
    Stealth,
    Survival,

    NUM_SKILLS,
};

enum class PassiveSkillType
{
    Perception,
    Investigation,
    Insight,

    NUM_PASSIVE_SKILLS,
};

namespace Core
{
    static const std::string getAbilityString(const AbilityType at)
    {
        switch (at)
        {
            case AbilityType::Strength: return "Strength";
            case AbilityType::Dexterity: return "Dexterity";
            case AbilityType::Constitution: return "Constitution";
            case AbilityType::Intelligence: return "Intelligence";
            case AbilityType::Wisdom: return "Wisdom";
            case AbilityType::Charisma: return "Charisma";
            default: return "";
        }
    }

    static const std::string getAbilityShortString(const AbilityType at)
    {
        switch (at)
        {
            case AbilityType::Strength: return "STR";
            case AbilityType::Dexterity: return "DEX";
            case AbilityType::Constitution: return "CON";
            case AbilityType::Intelligence: return "INT";
            case AbilityType::Wisdom: return "WIS";
            case AbilityType::Charisma: return "CHA";
            default: return "";
        }
    }

    static const std::string getSkillString(const SkillType st)
    {
        switch (st)
        {
            case SkillType::Acrobatics: return "Acrobatics";
            case SkillType::AnimalHandling: return "Animal Handling";
            case SkillType::Arcana: return "Arcana";
            case SkillType::Athletics: return "Athletics";
            case SkillType::Deception: return "Deception";
            case SkillType::History: return "History";
            case SkillType::Insight: return "Insight";
            case SkillType::Intimidation: return "Intimidation";
            case SkillType::Investigation: return "Investigation";
            case SkillType::Medicine: return "Medicine";
            case SkillType::Nature: return "Nature";
            case SkillType::Perception: return "Perception";
            case SkillType::Performance: return "Performance";
            case SkillType::Persuasion: return "Persuasion";
            case SkillType::Religion: return "Religion";
            case SkillType::SleightOfHand: return "Sleight of Hand";
            case SkillType::Stealth: return "Stealth";
            case SkillType::Survival: return "Survival";
            default: return "";
        }
    }
};

struct Abilities
{
    Abilities() {}
    Abilities(int str, int dex, int con, int _int, int wis, int cha)
        : STR(str), DEX(dex), CON(con), INT(_int), WIS(wis), CHA(cha)
    {}

    const int getAbility(const AbilityType type) const;
    void setAbility(const AbilityType type, const int val);

    const int getModifier(const AbilityType at) const;

    int STR = 0;
    int DEX = 0;
    int CON = 0;
    int INT = 0;
    int WIS = 0;
    int CHA = 0;
};

struct Skills
{
    Skills() {}
    Skills(
        const int acr,
        const int ani,
        const int arc,
        const int ath,
        const int dec,
        const int his,
        const int ins,
        const int _int,
        const int inv,
        const int med,
        const int nat,
        const int perc,
        const int perf,
        const int pers,
        const int rel,
        const int sle,
        const int ste,
        const int sur)
        : acrobatics(acr), animal_handling(ani), arcana(arc), athletics(ath), deception(dec), history(his),
          insight(ins), intimidation(_int), investigation(inv), medicine(med), nature(nat), perception(perc),
          performance(perf), persuasion(pers), religion(rel), sleight_of_hand(sle), stealth(ste), survival(sur)
    {}

    const int getSkill(const SkillType st) const;
    void setSkill(const SkillType st, const int val);

    const int getModifier(const SkillType st) const;


    int acrobatics = 0;
    int animal_handling = 0;
    int arcana = 0;
    int athletics = 0;
    int deception = 0;
    int history = 0;
    int insight = 0;
    int intimidation = 0;
    int investigation = 0;
    int medicine = 0;
    int nature = 0;
    int perception = 0;
    int performance = 0;
    int persuasion = 0;
    int religion = 0;
    int sleight_of_hand = 0;
    int stealth = 0;
    int survival = 0;
};

struct PassiveSkills
{
    PassiveSkills() {}
    PassiveSkills(const int per, const int inv, const int ins) : perception(per), investigation(inv), insight(ins) {}

    const int getPassiveSkill(const PassiveSkillType pst) const;
    void setPassiveSkill(const PassiveSkillType pst, const int val);

    int perception = 0;
    int investigation = 0;
    int insight = 0;
};
