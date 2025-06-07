#include "ActionsElement.hpp"

#include "imgui.h"

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
            switch (action->getLimitType())
            {
                case ActionLimitType::PerDay:
                {
                    const auto m = action->getPerDayMax();
                    const auto c = action->getPerDayCurrent();
                    ImGui::Text("%i %s per day (%i left)", m, m > 1 ? "uses" : "use", c);
                    break;
                }
                case ActionLimitType::RechargeRest:
                {
                    ImGui::Text("Recharges after a long rest");
                    break;
                }
                case ActionLimitType::RechargeRoll:
                {
                    ImGui::Text("Recharge %i-6", action->getRechargeRollMinimum());
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
