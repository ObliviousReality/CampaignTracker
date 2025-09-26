#pragma once

#include "Entity.hpp"

#include "data/ActionType.hpp"

#include <set>
#include <string>

class Action;

using Actions = std::set<EntityId>;

class Action : public Entity
{
public:
    Action(EntityId id) : Entity(id, EntityType::Action) {}

    void constructFromTemplate(EntityId templateId);

    void setName(std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

    void setDescription(std::string newDesc) { description = newDesc; }
    const std::string & getDescription() const { return description; }

    void setLimitType(const std::pair<ActionLimitType, int> & limitToVal)
    {
        setLimitType(limitToVal.first, limitToVal.second);
    }

    void setLimitType(const ActionLimitType alt, const int val = 0);

    const ActionLimitType getLimitType() const { return limitType; }

    const int getRechargeRollMinimum() const { return rechargeRollMinimum; }
    const int getPerDayMax() const { return perDayMax; }
    const int getPerDayCurrent() const { return perDayCurrent; }

    void useAction();

    bool canDoAction() const { return chargeAvailable; }

    void reset();

private:
    std::string name;
    std::string description;
    ActionLimitType limitType = ActionLimitType::None;

    int perDayMax = 0;
    int perDayCurrent = 0;

    int rechargeRollMinimum = 5;
    bool chargeAvailable = true;
};
