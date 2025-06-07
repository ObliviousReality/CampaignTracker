#pragma once

#include <string>

enum class ActionLimitType
{
    PerDay,
    RechargeRoll,
    RechargeRest,
    None,
};

class Action
{
public:
    Action() {}

    void setName(std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

    void setDescription(std::string newDesc) { description = newDesc; }
    const std::string & getDescription() const { return description; }

    void setLimitType(const ActionLimitType alt, const int val)
    {
        limitType = alt;

        switch (alt)
        {
            case ActionLimitType::PerDay:
            {
                perDayCurrent = val;
                perDayMax = val;
                break;
            }
            case ActionLimitType::RechargeRoll:
            {
                rechargeRollMinimum = val;
                break;
            }
            case ActionLimitType::RechargeRest: // nothing to do here, fallthrough
            case ActionLimitType::None:
            {
                // Shouldn't occur
                break;
            }
        }
    }

    void useAction()
    {
        switch (limitType)
        {
            case ActionLimitType::PerDay:
            {
                if (perDayCurrent)
                {
                    perDayCurrent--;
                }
                break;
            }
            case ActionLimitType::RechargeRoll:
            case ActionLimitType::RechargeRest:
            {
                if (chargeAvailable)
                {
                    chargeAvailable = false;
                }
                // nothing to do here
                break;
            }
            case ActionLimitType::None:
            {
                // Shouldn't occur
                break;
            }
        }
    }

    bool canDoAction() { return (perDayCurrent > perDayMax) || chargeAvailable; }

    void reset()
    {
        perDayCurrent = perDayMax;
        chargeAvailable = true;
    }

private:
    std::string name;
    std::string description;
    ActionLimitType limitType = ActionLimitType::None;

    int perDayMax = 0;
    int perDayCurrent = 0;

    int rechargeRollMinimum = 5;
    bool chargeAvailable = true;
};