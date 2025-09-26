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

    auto * core = CTCore::Get();

    for (const auto templateId : t->getActions())
    {
        auto id = core->createActionFromTemplate(templateId);
        addAction(id);
    }

    for (const auto templateId : t->getBonusActions())
    {
        auto id = core->createActionFromTemplate(templateId);
        addBonusAction(id);
    }

    for (const auto templateId : t->getReactions())
    {
        auto id = core->createActionFromTemplate(templateId);
        addReaction(id);
    }

    for (const auto templateId : t->getLegendaryActions())
    {
        auto id = core->createActionFromTemplate(templateId);
        addLegendaryAction(id);
    }

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
