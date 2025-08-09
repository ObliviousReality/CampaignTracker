#pragma once

#include "Template.hpp"

#include "data/Action.hpp"
#include "data/MonsterType.hpp"

#include <string>
#include <vector>

class MonsterTemplate : public Template
{
public:
    MonsterTemplate(EntityId id) : Template(id, EntityType::MonsterTemplate) {}

    const int getChallengeRating() const { return challengeRating; }
    void setChallengeRating(const int newCR) { challengeRating = newCR; }

    const std::vector<Action *> & getActions() const { return actions; }
    void setActions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getBonusActions() const { return bonusActions; }
    void setBonusActions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getReactions() const { return reactions; }
    void setReactions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getLegendaryActions() const { return legendaryActions; }
    void setLegendaryActions(const std::vector<Action *> & acts) { actions = acts; }

    void setMonsterType(const MonsterType newMonsterType) { monsterType = newMonsterType; }
    const MonsterType getMonsterType() const { return monsterType; }

    void addAction(Action * action) { actions.emplace_back(action); }
    void addBonusAction(Action * action) { bonusActions.emplace_back(action); }
    void addLegendaryAction(Action * action) { legendaryActions.emplace_back(action); }
    void addReaction(Action * action) { reactions.emplace_back(action); }

private:
    int challengeRating = 0;
    MonsterType monsterType;

    std::vector<Action *> actions = {};
    std::vector<Action *> bonusActions = {};
    std::vector<Action *> legendaryActions = {};
    std::vector<Action *> reactions = {};
};
