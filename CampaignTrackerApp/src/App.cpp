#include "Core/Core.hpp"

#include "entities/Creature.hpp"

#include <iostream>
#include <map>
#include <memory>

void printDetails(Player * p)
{
    const auto race = Core::getRaceString(p->getRaceType());
    const auto clas = Core::getClassString(p->getClassType());

    const auto alignment = Core::getAlignmentString(p->getAlignment());

    printf("%s (%s)\n", p->getName().c_str(), p->getHumanName().c_str());
    printf("%s/%s/%i/%s\n", race.c_str(), clas.c_str(), p->getLevel(), alignment.c_str());
    printf("STR DEX CON INT WIS CHA\n");
    auto * abilities = p->getAbilities();
    printf(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        abilities->getModifier(AbilityType::Strength),
        abilities->getModifier(AbilityType::Dexterity),
        abilities->getModifier(AbilityType::Constitution),
        abilities->getModifier(AbilityType::Intelligence),
        abilities->getModifier(AbilityType::Wisdom),
        abilities->getModifier(AbilityType::Charisma));

    printf("STR DEX CON INT WIS CHA\n");
    printf(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        p->getSavingThrowModifier(AbilityType::Strength),
        p->getSavingThrowModifier(AbilityType::Dexterity),
        p->getSavingThrowModifier(AbilityType::Constitution),
        p->getSavingThrowModifier(AbilityType::Intelligence),
        p->getSavingThrowModifier(AbilityType::Wisdom),
        p->getSavingThrowModifier(AbilityType::Charisma));

    printf("%i (%i) / %i\n", p->getHitPoints(), p->getTempHitPoints(), p->getHitPointsMax());

    printf("Init / Insp / Prof / AC\n");
    printf(
        "+%i      %s    +%i    %i\n",
        p->getInitiative(),
        p->hasInspiration() ? "yes" : "no ",
        p->getProficiency(),
        p->getAC());

    printf("PER / INV / INS  SPEED\n");
    auto * passives = p->getPassives();
    printf(
        " %i   %i   %i        %ift\n",
        passives->perception,
        passives->investigation,
        passives->insight,
        p->getSpeed());

    printf(" 1 2 3 4 5 6 7 8\n");
    printf(" 0 0 0 0 0 0 0 0\n"); // Spell slots
    printf("Conditions:\n");
    for (const auto con : p->getConditions())
    {
        printf("%s, ", Condition::getConditionString(con).c_str());
    }
    printf("\n");
    printf("Immunities:\n");
    for (const auto con : p->getConditionImmunities())
    {
        printf("%s, ", Condition::getConditionString(con).c_str());
    }
    for (const auto dt : p->getDamageTypeImmunities())
    {
        printf("%s, ", Core::getDamageTypeString(dt).c_str());
    }
    printf("\n");
    printf("Resistances:\n");
    for (const auto res : p->getResistances())
    {
        printf("%s, ", Core::getDamageTypeString(res).c_str());
    }
    printf("\n");
    printf("Senses:\n");
    for (const auto sense : p->getSenses())
    {
        printf("%s, ", Core::getSenseString(sense).c_str());
    }
    printf("\n");

    printf("Skills:\n");
    auto printSkill = [&p](const SkillType st)
    {
        const auto skill = p->getSkill(st);
        printf("%s: %c%i\n", Core::getSkillString(st).c_str(), skill >= 0 ? '+' : '-', skill);
    };
    printSkill(SkillType::Acrobatics);
    printSkill(SkillType::AnimalHandling);
    printSkill(SkillType::Arcana);
    printSkill(SkillType::Athletics);
    printSkill(SkillType::Deception);
    printSkill(SkillType::History);
    printSkill(SkillType::Deception);
    printSkill(SkillType::History);
    printSkill(SkillType::Insight);
    printSkill(SkillType::Intimidation);
    printSkill(SkillType::Investigation);
    printSkill(SkillType::Medicine);
    printSkill(SkillType::Nature);
    printSkill(SkillType::Perception);
    printSkill(SkillType::Performance);
    printSkill(SkillType::Persuasion);
    printSkill(SkillType::Religion);
    printSkill(SkillType::SleightOfHand);
    printSkill(SkillType::Stealth);
    printSkill(SkillType::Survival);
}

int main()
{
    std::unique_ptr<CTCore> core = std::make_unique<CTCore>();
    CTCore::PrintHelloWorld();

    auto p = core->createPlayer(
        "Berthog",
        ClassType::Warlock,
        RaceType::Dwarf,
        "Tom",
        8,
        { MoralityType::Good, OrderType::Lawful });

    p->addSense(SenseType::Darkvision);
    p->setAC(17);
    p->setInitiative(3);
    p->setSpeed(25);
    p->setProficiency(3);
    p->setPassiveAbility(PassiveSkillType::Perception, 15);
    p->setPassiveAbility(PassiveSkillType::Investigation, 18);
    p->setPassiveAbility(PassiveSkillType::Insight, 12);
    p->addResistance(DamageType::Poison);
    p->setHitPoints(83);
    p->setMaxHitPoints(83);
    p->setTempHitPoint(5);

    p->setAbility(AbilityType::Strength, 20);
    p->setAbility(AbilityType::Dexterity, 17);
    p->setAbility(AbilityType::Constitution, 18);
    p->setAbility(AbilityType::Intelligence, 15);
    p->setAbility(AbilityType::Wisdom, 14);
    p->setAbility(AbilityType::Charisma, 15);

    p->setTaggedSkill(SkillType::AnimalHandling);
    p->setTaggedSkill(SkillType::Deception);
    p->setTaggedSkill(SkillType::Investigation, 2);
    p->setTaggedSkill(SkillType::Perception);
    p->setTaggedSkill(SkillType::Survival);

    p->setTaggedSavingThrow(AbilityType::Wisdom);
    p->setTaggedSavingThrow(AbilityType::Charisma);

    p->generateSkills();
    printDetails(p);

    std::cin.get();
    return 0;
}