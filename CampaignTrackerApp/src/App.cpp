#include "Core/Core.hpp"

#include "entities/Creature.hpp"

#include <iostream>
#include <map>
#include <memory>

void printDetails(Player * p, CTCore * core)
{
    const auto race = core->getRaceString(p->getRaceType());
    const auto clas = core->getClassString(p->getClassType());

    const auto alignment = core->getAlignmentString(p->getAlignment());

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
    auto * savingThrows = p->getSavingThrows();
    printf(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        savingThrows->getModifier(AbilityType::Strength),
        savingThrows->getModifier(AbilityType::Dexterity),
        savingThrows->getModifier(AbilityType::Constitution),
        savingThrows->getModifier(AbilityType::Intelligence),
        savingThrows->getModifier(AbilityType::Wisdom),
        savingThrows->getModifier(AbilityType::Charisma));

    printf("%i (%i) / %i\n", p->getHitPoints(), p->getTempHitPoints(), p->getHitPointsMax());

    printf("Init / Insp / AC\n");
    printf("+%i      %s    %i\n", p->getInitiative(), p->hasInspiration() ? "yes" : "no ", p->getAC());

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
        printf("%s, ", core->getConditionString(con).c_str());
    }
    printf("\n");
    printf("Immunities:\n");
    for (const auto con : p->getConditionImmunities())
    {
        printf("%s, ", core->getConditionString(con).c_str());
    }
    for (const auto dt : p->getDamageTypeImmunities())
    {
        printf("%s, ", core->getDamageTypeString(dt).c_str());
    }
    printf("\n");
    printf("Resistances:\n");
    for (const auto res : p->getResistances())
    {
        printf("%s, ", core->getDamageTypeString(res).c_str());
    }
    printf("\n");
    printf("Senses:\n");
    for (const auto sense : p->getSenses())
    {
        printf("%s, ", core->getSenseString(sense).c_str());
    }
    printf("\n");
}

int main()
{
    std::unique_ptr<CTCore> core = std::make_unique<CTCore>();
    CTCore::PrintHelloWorld();

    core->initalise();

    //std::cout << "Classes:" << std::endl;
    //for (const auto & c : core->getClasses())
    //{
    //    std::cout << c.second->getName() << std::endl;
    //}
    //std::cout << "Races:" << std::endl;
    //for (const auto & c : core->getRaces())
    //{
    //    std::cout << c.second->getName() << std::endl;
    //}
    //std::cout << "Conditions:" << std::endl;
    //for (const auto & c : core->getConditions())
    //{
    //    std::cout << c.second->getName() << std::endl;
    //}
    //std::cout << "Damage Types:" << std::endl;
    //for (const auto & c : core->getDamageTypes())
    //{
    //    std::cout << c.second->getName() << std::endl;
    //}
    //std::cout << "Senses:" << std::endl;
    //for (const auto & c : core->getSenses())
    //{
    //    std::cout << c.second->getName() << std::endl;
    //}

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

    printDetails(p, core.get());

    std::cin.get();
    return 0;
}