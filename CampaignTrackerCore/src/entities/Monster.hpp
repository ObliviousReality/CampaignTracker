#pragma once

#include "Creature.hpp"

#include "data/Action.hpp"
#include "data/MonsterType.hpp"

class Monster : public Creature
{
public:
    Monster(EntityId id) : Creature(id, EntityType::Monster, CreatureType::Monster) {}

    void constructFromTemplate(EntityId templateId) override;

    void generateSkills() override;

    void setMonsterTypeName(const std::string newName) { monsterTypeName = newName; }
    const std::string & getMonsterTypeName() const { return monsterTypeName; }

    void setChallengeRating(const int newCR) { challengeRating = newCR; }
    const int getChallengeRating() const { return challengeRating; }

    void setMonsterType(const MonsterType newMonsterType) { monsterType = newMonsterType; }
    const MonsterType getMonsterType() const { return monsterType; }

    void addAction(Action * action) { actions.emplace_back(action); }
    void addBonusAction(Action * action) { bonusActions.emplace_back(action); }
    void addLegendaryAction(Action * action) { legendaryActions.emplace_back(action); }
    void addReaction(Action * action) { reactions.emplace_back(action); }

    const std::vector<Action *> & getActions() const { return actions; }
    void setActions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getBonusActions() const { return bonusActions; }
    void setBonusActions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getReactions() const { return reactions; }
    void setReactions(const std::vector<Action *> & acts) { actions = acts; }

    const std::vector<Action *> & getLegendaryActions() const { return legendaryActions; }
    void setLegendaryActions(const std::vector<Action *> & acts) { actions = acts; }

private:
    std::string monsterTypeName;
    int challengeRating;
    MonsterType monsterType;

    std::vector<Action *> actions;
    std::vector<Action *> bonusActions;
    std::vector<Action *> legendaryActions;
    std::vector<Action *> reactions;
};
