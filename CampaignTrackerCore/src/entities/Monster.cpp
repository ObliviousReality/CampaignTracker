#include "Monster.hpp"

#include <cmath>

void Monster::generateSkills()
{
    setHitPoints(getHitPointsMax());

    const auto cr = getChallengeRating();

    const auto prof = static_cast<int>(std::ceil(static_cast<float>(cr) / 4.0f)) + 1;

    setProficiency(prof);
    Creature::generateSkills();
}
