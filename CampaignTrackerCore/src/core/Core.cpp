#include "Core.hpp"

#include <iostream>

void CTCore::initalise()
{
    // init classes
    classes.emplace(ClassType::Barbarian, std::make_shared<Class>("Barbarian"));
    classes.emplace(ClassType::Bard, std::make_shared<Class>("Bard"));
    classes.emplace(ClassType::Cleric, std::make_shared<Class>("Cleric"));
    classes.emplace(ClassType::Druid, std::make_shared<Class>("Druid"));
    classes.emplace(ClassType::Fighter, std::make_shared<Class>("Fighter"));
    classes.emplace(ClassType::Monk, std::make_shared<Class>("Monk"));
    classes.emplace(ClassType::Paladin, std::make_shared<Class>("Paladin"));
    classes.emplace(ClassType::Ranger, std::make_shared<Class>("Ranger"));
    classes.emplace(ClassType::Rogue, std::make_shared<Class>("Rogue"));
    classes.emplace(ClassType::Sorcerer, std::make_shared<Class>("Sorcerer"));
    classes.emplace(ClassType::Warlock, std::make_shared<Class>("Warlock"));
    classes.emplace(ClassType::Wizard, std::make_shared<Class>("Wizard"));
    classes.emplace(ClassType::Artificer, std::make_shared<Class>("Artificer"));

    // init races

    races.emplace(RaceType::Aasimar, std::make_shared<Race>("Aasimar"));
    races.emplace(RaceType::Dragonborn, std::make_shared<Race>("Dragonborn"));
    races.emplace(RaceType::Dwarf, std::make_shared<Race>("Dwarf"));
    races.emplace(RaceType::Elf, std::make_shared<Race>("Elf"));
    races.emplace(RaceType::Gnome, std::make_shared<Race>("Gnome"));
    races.emplace(RaceType::Goliath, std::make_shared<Race>("Goliath"));
    races.emplace(RaceType::Halfling, std::make_shared<Race>("Halfling"));
    races.emplace(RaceType::Human, std::make_shared<Race>("Human"));
    races.emplace(RaceType::Orc, std::make_shared<Race>("Orc"));
    races.emplace(RaceType::Tiefling, std::make_shared<Race>("Tiefling"));
    races.emplace(RaceType::HalfElf, std::make_shared<Race>("Half Elf"));
    races.emplace(RaceType::Aarakocra, std::make_shared<Race>("Aarakocra"));
    races.emplace(RaceType::Genasi, std::make_shared<Race>("Genasi"));
    races.emplace(RaceType::HalfOrc, std::make_shared<Race>("Half Orc"));
    races.emplace(RaceType::Gith, std::make_shared<Race>("Githyanki"));
}

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer(const std::string & name, const ClassType classType, const RaceType raceType)
{
    Player * p = new Player(name, classType, raceType);
    creatures.emplace(p);
    return p;
}

Creature * CTCore::createCreature(const std::string & name)
{
    Creature * c = new Creature(name);
    creatures.emplace(c);
    return c;
}
