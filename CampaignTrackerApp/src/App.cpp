#include "Core/Core.hpp"

#include "entities/Creature.hpp"

#include <iostream>
#include <map>
#include <memory>

void printDetails(Player * p, CTCore * core)
{
    const auto race = core->getRaceString(p->getRaceType());
    const auto clas = core->getClassString(p->getClassType());
    printf("Name:\t%s\nRace:\t%s\nClass:\t%s\n", p->getName().c_str(), race.c_str(), clas.c_str());
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