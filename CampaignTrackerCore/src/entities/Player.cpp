#include "Player.hpp"

Player::Player(
    const std::string name,
    const ClassType ct,
    const RaceType rt,
    const std::string humanName,
    const int level,
    const std::pair<MoralityType, OrderType> alignment)
    : Creature(name, alignment), classType(ct), raceType(rt), humanPlayerName(humanName), level(level)
{
    spellSlotManager = std::make_unique<SpellSlotManager>();
}

void Player::generateSkills()
{
    const int proficiencyBonus = static_cast<int>(ceil(level / 4)) + 1;
    setProficiency(proficiencyBonus);

    Creature::generateSkills();
}
