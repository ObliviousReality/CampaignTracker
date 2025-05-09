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

namespace Core
{
    static const std::string getRaceString(const RaceType rt)
    {
        switch (rt)
        {
            case RaceType::Aasimar: return "Aasimar";
            case RaceType::Dragonborn: return "Dragonborn";
            case RaceType::Dwarf: return "Dwarf";
            case RaceType::Elf: return "Elf";
            case RaceType::Gnome: return "Gnome";
            case RaceType::Goliath: return "Goliath";
            case RaceType::Halfling: return "Halfling";
            case RaceType::Human: return "Human";
            case RaceType::Orc: return "Orc";
            case RaceType::Tiefling: return "Tiefling";
            case RaceType::HalfElf: return "Half Elf";
            case RaceType::Aarakocra: return "Aarakocra";
            case RaceType::Genasi: return "Genasi";
            case RaceType::HalfOrc: return "Half Orc";
            case RaceType::Gith: return "Githyanki";
            default: return "";
        }
    }

    static const int getRaceSpeed(const RaceType rt)
    {
        // https://docs.google.com/spreadsheets/d/1vvMGY0KZjkJVjDNoa3P-v51dbE1dCD6Bnauko9qTYqo/edit?gid=0#gid=0
        switch (rt)
        {
            case RaceType::Aarakocra:
            case RaceType::Dwarf:
            case RaceType::Gnome:
            case RaceType::Halfling: return 25;
            default: return 30;
        }
    }
};
