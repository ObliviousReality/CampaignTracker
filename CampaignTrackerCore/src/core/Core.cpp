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

    // init conditions

    conditions.emplace(ConditionType::Blinded, std::make_shared<Condition>("Blinded"));
    conditions.emplace(ConditionType::Charmed, std::make_shared<Condition>("Charmed"));
    conditions.emplace(ConditionType::Deafened, std::make_shared<Condition>("Deafened"));
    conditions.emplace(ConditionType::Frightened, std::make_shared<Condition>("Frightened"));
    conditions.emplace(ConditionType::Grappled, std::make_shared<Condition>("Grappled"));
    conditions.emplace(ConditionType::Incapacitated, std::make_shared<Condition>("Incapacitated"));
    conditions.emplace(ConditionType::Invisible, std::make_shared<Condition>("Invisible"));
    conditions.emplace(ConditionType::Paralysed, std::make_shared<Condition>("Paralysed"));
    conditions.emplace(ConditionType::Petrified, std::make_shared<Condition>("Petrified"));
    conditions.emplace(ConditionType::Poisoned, std::make_shared<Condition>("Poisoned"));
    conditions.emplace(ConditionType::Prone, std::make_shared<Condition>("Prone"));
    conditions.emplace(ConditionType::Restrained, std::make_shared<Condition>("Restrained"));
    conditions.emplace(ConditionType::Stunned, std::make_shared<Condition>("Stunned"));
    conditions.emplace(ConditionType::Unconscious, std::make_shared<Condition>("Unconscious"));
    conditions.emplace(ConditionType::Exhaustion, std::make_shared<Condition>("Exhaustion"));

    // init damage types

    damageTypes.emplace(DamageType::Acid, std::make_shared<DamageTypeObj>("Acid"));
    damageTypes.emplace(DamageType::Bludgeoning, std::make_shared<DamageTypeObj>("Bludgeoning"));
    damageTypes.emplace(DamageType::Cold, std::make_shared<DamageTypeObj>("Cold"));
    damageTypes.emplace(DamageType::Fire, std::make_shared<DamageTypeObj>("Fire"));
    damageTypes.emplace(DamageType::Force, std::make_shared<DamageTypeObj>("Force"));
    damageTypes.emplace(DamageType::Lightning, std::make_shared<DamageTypeObj>("Lightning"));
    damageTypes.emplace(DamageType::Necrotic, std::make_shared<DamageTypeObj>("Necrotic"));
    damageTypes.emplace(DamageType::Piercing, std::make_shared<DamageTypeObj>("Piercing"));
    damageTypes.emplace(DamageType::Poison, std::make_shared<DamageTypeObj>("Poison"));
    damageTypes.emplace(DamageType::Psychic, std::make_shared<DamageTypeObj>("Psychic"));
    damageTypes.emplace(DamageType::Radiant, std::make_shared<DamageTypeObj>("Radiant"));
    damageTypes.emplace(DamageType::Slashing, std::make_shared<DamageTypeObj>("Slashing"));
    damageTypes.emplace(DamageType::Thunder, std::make_shared<DamageTypeObj>("Thunder"));

    // init senses

    senses.emplace(SenseType::Blindsight, std::make_shared<Sense>("Blindsight"));
    senses.emplace(SenseType::Darkvision, std::make_shared<Sense>("Darkvision"));
    senses.emplace(SenseType::Tremorsense, std::make_shared<Sense>("Tremorsense"));
    senses.emplace(SenseType::Truesight, std::make_shared<Sense>("Truesight"));

    // init alignments

    moralities.emplace(MoralityType::None, std::make_shared<Morality>("None"));
    moralities.emplace(MoralityType::Good, std::make_shared<Morality>("Good"));
    moralities.emplace(MoralityType::Neutral, std::make_shared<Morality>("Neutral"));
    moralities.emplace(MoralityType::Evil, std::make_shared<Morality>("Evil"));

    orders.emplace(OrderType::None, std::make_shared<Order>("None"));
    orders.emplace(OrderType::Lawful, std::make_shared<Order>("Lawful"));
    orders.emplace(OrderType::Neutral, std::make_shared<Order>("Neutral"));
    orders.emplace(OrderType::Chaotic, std::make_shared<Order>("Chaotic"));
}

void CTCore::PrintHelloWorld() { std::cout << "Hello World!\n"; }

Player * CTCore::createPlayer(
    const std::string & name,
    const ClassType classType,
    const RaceType raceType,
    const std::string & human,
    const int level,
    const std::pair<MoralityType, OrderType> alignment)
{
    Player * p = new Player(name, classType, raceType, human, level, alignment);
    creatures.emplace(p);
    return p;
}

const std::string CTCore::getAlignmentString(std::pair<MoralityType, OrderType> alignment) const
{
    return getAlignmentString(alignment.first, alignment.second);
}

const std::string CTCore::getAlignmentString(const MoralityType mt, const OrderType ot) const
{
    if (mt == MoralityType::Neutral && ot == OrderType::Neutral)
    {
        return "True Neutral";
    }
    return orders.find(ot)->second->getName() + " " + moralities.find(mt)->second->getName();
}

Creature * CTCore::createCreature(const std::string & name)
{
    Creature * c = new Creature(name, { MoralityType::None, OrderType::None });
    creatures.emplace(c);
    return c;
}
