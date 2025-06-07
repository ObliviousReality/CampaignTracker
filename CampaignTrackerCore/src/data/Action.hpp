#pragma once

#include <string>

enum class ActionLimitType
{
    PerDay,
    RechargeRoll,
    RechargeLongRest,
    RechargeShortRest,
    None,
};

namespace Core
{
    static std::string getActionLimitTypeString(const ActionLimitType atl)
    {
        switch (atl)
        {
            case ActionLimitType::PerDay: return "%i %s per day (%i left)";
            case ActionLimitType::RechargeRoll: return "Recharge %i-6";
            case ActionLimitType::RechargeLongRest: return "Recharges after a long rest";
            case ActionLimitType::RechargeShortRest: return "Recharges after a short rest";
            case ActionLimitType::None: return "";
        }
        return {};
    }
};

class Action
{
public:
    Action() {}

    void setName(std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

    void setDescription(std::string newDesc) { description = newDesc; }
    const std::string & getDescription() const { return description; }

    void setLimitType(const ActionLimitType alt, const int val = 0)
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
            case ActionLimitType::RechargeLongRest: // nothing to do here, fallthrough
            case ActionLimitType::RechargeShortRest: // nothing to do here, fallthrough
            case ActionLimitType::None:
            {
                // Shouldn't occur
                break;
            }
        }
    }

    const ActionLimitType getLimitType() const { return limitType; }

    const int getRechargeRollMinimum() const { return rechargeRollMinimum; }
    const int getPerDayMax() const { return perDayMax; }
    const int getPerDayCurrent() const { return perDayCurrent; }

    void useAction()
    {
        switch (limitType)
        {
            case ActionLimitType::PerDay:
            {
                if (perDayCurrent)
                {
                    perDayCurrent--;
                    if (!perDayCurrent)
                    {
                        chargeAvailable = false;
                    }
                }
                break;
            }
            case ActionLimitType::RechargeRoll:
            case ActionLimitType::RechargeShortRest:
            case ActionLimitType::RechargeLongRest:
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

    bool canDoAction() { return chargeAvailable; }

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