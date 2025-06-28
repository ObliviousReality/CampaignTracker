#include "ActionsElement.hpp"

#include <imgui.h>

void ActionsElement::draw()
{
    auto * m = CTCore::Get()->getMonsterFromId(id);
    const auto & actions = m->getActions();
    if (actions.size())
    {
        ImGui::SeparatorText("Actions");
        for (auto action : actions)
        {
            const auto canDoAction = action->canDoAction();
            if (!canDoAction)
            {
                ImGui::BeginDisabled();
            }
            ImGui::Text(action->getName().c_str());
            bool showUseReset = true;
            const auto limitText = Core::getActionLimitTypeString(action->getLimitType());
            switch (action->getLimitType())
            {
                case ActionLimitType::PerDay:
                {
                    const auto m = action->getPerDayMax();
                    const auto c = action->getPerDayCurrent();
                    ImGui::Text(limitText.c_str(), m, m > 1 ? "uses" : "use", c);
                    break;
                }
                case ActionLimitType::RechargeShortRest:
                case ActionLimitType::RechargeLongRest:
                {
                    ImGui::Text(limitText.c_str());
                    break;
                }
                case ActionLimitType::RechargeRoll:
                {
                    ImGui::Text(limitText.c_str(), action->getRechargeRollMinimum());
                    break;
                }
                default:
                {
                    showUseReset = false;
                    break;
                }
            }
            ImGui::TextWrapped(action->getDescription().c_str());
            if (showUseReset)
            {
                const auto buttonId = "Use##" + action->getName();
                if (ImGui::Button(buttonId.c_str()))
                {
                    action->useAction();
                }

                ImGui::SameLine();
            }
            if (!canDoAction)
            {
                ImGui::EndDisabled();
            }
            if (showUseReset)
            {
                const auto buttonId = "Reset##" + action->getName();
                if (ImGui::Button(buttonId.c_str()))
                {
                    action->reset();
                }
            }
        }
    }
}
