#include "MonsterFrame.hpp"

#include "FrameElements/ActionsElement.hpp"
#include "FrameElements/MonsterBioElement.hpp"
#include "FrameElements/SkillsElement.hpp"

#include "imgui.h"

MonsterFrame::MonsterFrame(EntityId _id) : monsterId(_id)
{
    bioElement = std::make_unique<MonsterBioElement>(monsterId);
    skillsElement = std::make_unique<SkillsElement>(monsterId, EntityType::Monster);
    actionsElement = std::make_unique<ActionsElement>(monsterId);
}

void MonsterFrame::render()
{
    auto * monster = CTCore::Get()->getMonsterFromId(monsterId);
    ImGui::BeginChild(monster->getName().c_str(), ImVec2(234, ImGui::GetContentRegionAvail().y));

    const auto titleText = monster->getName() + " (" + (monster->getMonsterTypeName()) + ")";
    ImGui::SeparatorText(titleText.c_str());
    auto & style = ImGui::GetStyle();
    auto oldPadding = style.FramePadding;
    style.FramePadding = ImVec2(17, 5);
    style.TabBarOverlineSize = 2;

    if (ImGui::BeginTabBar("tabs", ImGuiTabBarFlags_NoTooltip | ImGuiTabBarFlags_DrawSelectedOverline))
    {
        if (ImGui::BeginTabItem("Bio"))
        {
            style.FramePadding = oldPadding;
            bioElement->draw();
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(8, 5);
        if (ImGui::BeginTabItem("Skills"))
        {
            style.FramePadding = oldPadding;
            skillsElement->draw();
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(12, 5);
        if (ImGui::BeginTabItem("Actions"))
        {
            style.FramePadding = oldPadding;
            actionsElement->draw();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    style.FramePadding = oldPadding;
    ImGui::EndChild();
}
