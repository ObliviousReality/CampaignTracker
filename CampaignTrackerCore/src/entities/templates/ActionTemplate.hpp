#pragma once

#include "data/ActionType.hpp"

#include "Entities/Entity.hpp"

#include <string>

class ActionTemplate : public Entity
{
public:
    ActionTemplate(EntityId id) : Entity(id, EntityType::ActionTemplate) {}

    void setName(const std::string & newName) { name = newName; }
    const std::string & getName() const { return name; }

    void setDescription(const std::string & newDesc) { description = newDesc; }
    const std::string & getDescription() const { return description; }

    void setLimitType(const ActionLimitType alt, const int val = 0)
    {
        limitType = alt;

        switch (alt)
        {
            case ActionLimitType::PerDay:
            {
                perDayMax = val;
                break;
            }
            case ActionLimitType::RechargeRoll:
            {
                rechargeRollMinimum = val;
                break;
            }
            case ActionLimitType::RechargeLongRest: // nothing to do here, fallthrough
            case ActionLimitType::RechargeShortRest: // nothing to do here, fallthrough
            case ActionLimitType::None:
            {
                // Shouldn't occur
                break;
            }
        }
    }

    std::pair<ActionLimitType, int> getLimitType() const
    {
        switch (limitType)
        {
            case ActionLimitType::PerDay: return { limitType, perDayMax };
            case ActionLimitType::RechargeRoll: return { limitType, rechargeRollMinimum };
            default: return { limitType, 0 };
        }
    }

    const int getRechargeRollMinimum() const { return rechargeRollMinimum; }
    const int getPerDayMax() const { return perDayMax; }

private:
    std::string name;
    std::string description;
    ActionLimitType limitType = ActionLimitType::None;

    int perDayMax = 0;

    int rechargeRollMinimum = 5;
};
