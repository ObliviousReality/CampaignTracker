#pragma once
#include <string>

enum class RaceType
{
    Aasimar,
    Dragonborn,
    Dwarf,
    Elf,
    Gnome,
    Goliath,
    Halfling,
    Human,
    Orc,
    Tiefling,
    HalfElf,
    Aarakocra,
    Genasi,
    HalfOrc,
    Gith,
    NUM_RACES,
};

class Race
{
public:
    Race(std::string name) : name(name) {}

    std::string getName() { return name; }

private:
    std::string name;
};