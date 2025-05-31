#include "PlayerFrame.hpp"

#include "FrameElements/BioElement.hpp"
#include "FrameElements/NotesElement.hpp"
#include "FrameElements/SkillsElement.hpp"

#include "imgui.h"

#include <sstream>

PlayerFrame::PlayerFrame(Player * p) : player(p)
{
    bioElement = std::make_unique<BioElement>(p);
    skillsElement = std::make_unique<SkillsElement>(p); // TODO: This doesn't need to take p
    notesElement = std::make_unique<NotesElement>();
}

void PlayerFrame::render()
{
    ImGui::BeginChild(player->getName().c_str(), ImVec2(224, ImGui::GetContentRegionAvail().y));

    const auto titleText = player->getName() + " (" + (player->getHumanName()) + ")";
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
            notesElement->draw();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    style.FramePadding = oldPadding;
    ImGui::EndChild();
}

const std::string PlayerFrame::getName() { return player->getName(); }
