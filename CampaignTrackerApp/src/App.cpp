#include "Core/Core.hpp"

#include "entities/Creature.hpp"

#include <iostream>
#include <map>
#include <memory>

void printDetails(Player * p, CTCore * core)
{
    const auto race = core->getRaceString(p->getRaceType());
    const auto clas = core->getClassString(p->getClassType());

    printf("%s (NAME)\n", p->getName().c_str());
    printf("%s/%s/(LEVEL)/(ALIGNMENT)\n", race.c_str(), clas.c_str());
    printf("STR DEX CON INT WIS CHA\n");
    auto * abilities = p->getAbilities();
    printf(
        " %i   %i   %i   %i   %i   %i\n",
        abilities->STR,
        abilities->DEX,
        abilities->CON,
        abilities->INT,
        abilities->WIS,
        abilities->CHA);

    printf("STR DEX CON INT WIS CHA\n");
    auto * savingThrows = p->getSavingThrows();
    printf(
        " %i   %i   %i   %i   %i   %i\n",
        savingThrows->STR,
        savingThrows->DEX,
        savingThrows->CON,
        savingThrows->INT,
        savingThrows->WIS,
        savingThrows->CHA);

    printf("%i (%i) / %i\n", p->getHitPoints(), p->getTempHitPoints(), p->getHitPointsMax());

    printf("Init / Insp / AC\n");
    printf("%i      %s    %i\n", p->getInitiative(), p->hasInspiration() ? "yes" : "no ", p->getAC());

    printf("PER / INV / INS  SPEED\n");
    auto * passives = p->getPassives();
    printf(
        " %i   %i   %i        %ift\n",
        passives->perception,
        passives->investigation,
        passives->insight,
        p->getSpeed());
}

int main()
{
    std::unique_ptr<CTCore> core = std::make_unique<CTCore>();
    CTCore::PrintHelloWorld();

    core->initalise();

    std::cout << "Classes:" << std::endl;
    for (const auto & c : core->getClasses())
    {
        std::cout << c.second->getName() << std::endl;
    }
    std::cout << "Races:" << std::endl;
    for (const auto & c : core->getRaces())
    {
        std::cout << c.second->getName() << std::endl;
    }
    std::cout << "Conditions:" << std::endl;
    for (const auto & c : core->getConditions())
    {
        std::cout << c.second->getName() << std::endl;
    }
    std::cout << "Damage Types:" << std::endl;
    for (const auto & c : core->getDamageTypes())
    {
        std::cout << c.second->getName() << std::endl;
    }
    std::cout << "Senses:" << std::endl;
    for (const auto & c : core->getSenses())
    {
        std::cout << c.second->getName() << std::endl;
    }

    auto p = core->createPlayer("Gary", ClassType::Fighter, RaceType::Human);

    printDetails(p, core.get());

    std::cin.get();
    return 0;
}