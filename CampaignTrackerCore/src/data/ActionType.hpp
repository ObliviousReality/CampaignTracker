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
