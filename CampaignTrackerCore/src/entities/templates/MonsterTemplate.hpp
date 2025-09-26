#pragma once

#include "Template.hpp"

#include "data/MonsterType.hpp"

#include "entities/Action.hpp"

#include <string>
#include <vector>

class MonsterTemplate : public Template
{
public:
    MonsterTemplate(EntityId id) : Template(id, EntityType::MonsterTemplate) {}

    const int getChallengeRating() const { return challengeRating; }
    void setChallengeRating(const int newCR) { challengeRating = newCR; }

    const Actions & getActions() const { return actions; }
    void setActions(const Actions & acts) { actions = acts; }

    const Actions & getBonusActions() const { return bonusActions; }
    void setBonusActions(const Actions & acts) { bonusActions = acts; }

    const Actions & getReactions() const { return reactions; }
    void setReactions(const Actions & acts) { reactions = acts; }

    const Actions & getLegendaryActions() const { return legendaryActions; }
    void setLegendaryActions(const Actions & acts) { legendaryActions = acts; }

    void setMonsterType(const MonsterType newMonsterType) { monsterType = newMonsterType; }
    const MonsterType getMonsterType() const { return monsterType; }

    void addActionTemplate(EntityId action) { actions.emplace(action); }
    void addBonusActionTemplate(EntityId action) { bonusActions.emplace(action); }
    void addLegendaryActionTemplate(EntityId action) { legendaryActions.emplace(action); }
    void addReactionTemplate(EntityId action) { reactions.emplace(action); }

private:
    int challengeRating = 0;
    MonsterType monsterType;

    Actions actions = {};
    Actions bonusActions = {};
    Actions legendaryActions = {};
    Actions reactions = {};
};
