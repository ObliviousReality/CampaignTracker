#include "Monster.hpp"

#include "core/Core.hpp"

#include "templates/MonsterTemplate.hpp"

#include <cmath>

void Monster::constructFromTemplate(EntityId templateId)
{
    auto * t = static_cast<MonsterTemplate *>(CTCore::Get()->getEntity(templateId, EntityType::MonsterTemplate));
    if (!t)
    {
        // ASSERT()!;
        return;
    }

    setMonsterTypeName(t->getName());
    setMonsterType(t->getMonsterType());
    setChallengeRating(t->getChallengeRating());
    setSpeed(t->getSpeed());

    setActions(t->getActions());
    setBonusActions(t->getBonusActions());
    setReactions(t->getReactions());
    setLegendaryActions(t->getLegendaryActions());

    Creature::constructFromTemplate(templateId);

    generateSkills();
}

void Monster::generateSkills()
{
    setHitPoints(getHitPointsMax());

    const auto cr = getChallengeRating();

    const auto prof = static_cast<int>(std::ceil(static_cast<float>(cr) / 4.0f)) + 1;

    setProficiency(prof);
    Creature::generateSkills();
}
