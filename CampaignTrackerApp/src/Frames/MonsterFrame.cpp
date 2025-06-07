#include "MonsterFrame.hpp"

#include "FrameElements/ActionsElement.hpp"
#include "FrameElements/MonsterBioElement.hpp"
//#include "FrameElements/NotesElement.hpp"
#include "FrameElements/SkillsElement.hpp"

#include "imgui.h"

MonsterFrame::MonsterFrame(CreatureId _id) : monsterId(_id)
{
    bioElement = std::make_unique<MonsterBioElement>(monsterId);
    skillsElement = std::make_unique<SkillsElement>(monsterId, CreatureType::Monster);
    //notesElement = std::make_unique<NotesElement>();
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
    style.FramePadding = ImVec2(19, 5);
    style.TabBarOverlineSize = 2;

    if (ImGui::BeginTabBar("tabs", ImGuiTabBarFlags_NoTooltip | ImGuiTabBarFlags_DrawSelectedOverline))
    {
        if (ImGui::BeginTabItem("Bio"))
        {
            style.FramePadding = oldPadding;
            bioElement->draw();
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(10, 5);
        if (ImGui::BeginTabItem("Skills"))
        {
            style.FramePadding = oldPadding;
            skillsElement->draw();
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(15, 5);
        if (ImGui::BeginTabItem("Notes"))
        {
            style.FramePadding = oldPadding;
            //notesElement->draw();
            actionsElement->draw();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    style.FramePadding = oldPadding;
    ImGui::EndChild();
}
