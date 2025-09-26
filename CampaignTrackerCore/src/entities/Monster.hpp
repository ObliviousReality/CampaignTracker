#pragma once

#include "Creature.hpp"

#include "data/MonsterType.hpp"

#include "entities/Action.hpp"

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

    void addAction(EntityId actionId) { actions.emplace(actionId); }
    void addBonusAction(EntityId actionId) { bonusActions.emplace(actionId); }
    void addLegendaryAction(EntityId actionId) { legendaryActions.emplace(actionId); }
    void addReaction(EntityId actionId) { reactions.emplace(actionId); }

    const Actions & getActions() const { return actions; }
    void setActions(const Actions & acts) { actions = acts; }

    const Actions & getBonusActions() const { return bonusActions; }
    void setBonusActions(const Actions & acts) { bonusActions = acts; }

    const Actions & getReactions() const { return reactions; }
    void setReactions(const Actions & acts) { reactions = acts; }

    const Actions & getLegendaryActions() const { return legendaryActions; }
    void setLegendaryActions(const Actions & acts) { legendaryActions = acts; }

private:
    std::string monsterTypeName;
    int challengeRating;
    MonsterType monsterType;

    Actions actions;
    Actions bonusActions;
    Actions legendaryActions;
    Actions reactions;
};
