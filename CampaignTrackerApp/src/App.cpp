#include "Core/Core.hpp"

#include "entities/Creature.hpp"

#include <iostream>
#include <map>
#include <memory>

void printDetails(Creature * c, CTCore * core)
{
    const auto race = core->getRaceString(c->getRaceType());
    const auto clas = core->getClassString(c->getClassType());
    printf("Name:\t%s\nRace:\t%s\nClass:\t%s\n", c->getName().c_str(), race.c_str(), clas.c_str());
}

int main()
{
    std::unique_ptr<CTCore> core = std::make_unique<CTCore>();
    CTCore::PrintHelloWorld();

    core->initalise();

    for (const auto & c : core->getClasses()) { std::cout << c.second->getName() << std::endl; }
    for (const auto & c : core->getRaces()) { std::cout << c.second->getName() << std::endl; }

    auto c = core->createCreature("Gary", ClassType::Fighter, RaceType::Human);

    printDetails(c, core.get());

    std::cin.get();
}