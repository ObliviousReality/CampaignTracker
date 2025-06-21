#include "CharacterFrame.hpp"

#include "FrameElements/CharacterBioElement.hpp"
#include "FrameElements/NotesElement.hpp"
#include "FrameElements/SkillsElement.hpp"

#include "imgui.h"

#include <sstream>

CharacterFrame::CharacterFrame(EntityId id) : playerId(id)
{
    bioElement = std::make_unique<CharacterBioElement>(id);
    skillsElement = std::make_unique<SkillsElement>(id, EntityType::Character); // TODO: This doesn't need to take id?
    notesElement = std::make_unique<NotesElement>();
}

void CharacterFrame::render()
{
    auto * player = CTCore::Get()->getCharacterFromId(playerId);
    ImGui::BeginChild(player->getName().c_str(), ImVec2(234, ImGui::GetContentRegionAvail().y));
    std::string titleText;

    if (player->getCharacterType() == Character::Type::NPC)
    {
        titleText = player->getName() + " (NPC)";
    }
    else
    {
        titleText = player->getName() + " (" + (player->getHumanName()) + ")";
    }
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

const std::string CharacterFrame::getName() { return {}; }
