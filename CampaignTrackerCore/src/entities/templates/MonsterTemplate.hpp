#pragma once

#include "Template.hpp"

#include "data/Action.hpp"

#include <vector>>

class MonsterTemplate : public Template
{
public:
    MonsterTemplate(TemplateId id) : Template(id, TemplateType::Monster) {}

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

private:
    int challengeRating = 0;

    std::vector<Action *> actions = {};
    std::vector<Action *> bonusActions = {};
    std::vector<Action *> legendaryActions = {};
    std::vector<Action *> reactions = {};
};