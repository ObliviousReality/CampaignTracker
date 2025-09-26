#pragma once

#include "Action.hpp"

#include "entities/templates/ActionTemplate.hpp"

#include "core/Core.hpp"

void Action::constructFromTemplate(EntityId templateId)
{
    auto * t = static_cast<ActionTemplate *>(CTCore::Get()->getEntity(templateId, EntityType::ActionTemplate));
    setName(t->getName());
    setDescription(t->getDescription());
    setLimitType(t->getLimitType());
}

void Action::setLimitType(const ActionLimitType alt, const int val)
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

void Action::useAction()
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

void Action::reset()
{
    perDayCurrent = perDayMax;
    chargeAvailable = true;
}
