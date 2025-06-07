#include "PlayerBioElement.hpp"

#include "imgui.h"

#include <sstream>

void PlayerBioElement::olddraw()
{

}

void PlayerBioElement::drawCoreInfo()
{
    auto * player = CTCore::Get()->getCreatureFromId<Player>(getCreatureId(), CreatureType::Player);
    const auto race = Core::getRaceString(player->getRaceType());
    const auto clas = Core::getClassString(player->getClassType());

    const auto alignment = Core::getAlignmentString(player->getAlignment());
    ImGui::Text("Level: %i", player->getLevel());
    ImGui::Text("Race: %s", race.c_str());
    ImGui::Text("Class: %s", clas.c_str());
    ImGui::Text("Alignment: %s", alignment.c_str());
}

void PlayerBioElement::drawStats()
{
    auto * player = CTCore::Get()->getCreatureFromId<Player>(getCreatureId(), CreatureType::Player);
    ImGui::SeparatorText("Stats");

    ImGui::Button(("Init\n +" + std::to_string(player->getInitiative())).c_str());
    ImGui::SameLine();
    std::string inspText = "Insp\n " + std::string(player->hasInspiration() ? "Yes" : "No");
    if (ImGui::Button(inspText.c_str()))
    {
        player->setInspiration(!player->hasInspiration());
    }
    ImGui::SameLine();
    ImGui::Button(("Prof\n +" + std::to_string(player->getProficiency())).c_str());
    ImGui::SameLine();
    ImGui::Button((" AC \n " + std::to_string(player->getAC())).c_str());
    ImGui::SameLine();
    ImGui::Button(("Speed\n " + std::to_string(player->getSpeed()) + "ft").c_str());
}

void PlayerBioElement::drawSpells()
{
    auto * player = CTCore::Get()->getCreatureFromId<Player>(getCreatureId(), CreatureType::Player);
    ImGui::SeparatorText("Spell Slots");

    auto slots = player->getRemainingSpellSlots();
    for (int i = 0; i < 8; ++i)
    {
        ImGui::BeginGroup();
        if (ImGui::ArrowButton(("##upslots" + std::to_string(i)).c_str(), ImGuiDir::ImGuiDir_Up))
        {
            slots[i]++;
            slots[i] = std::min(slots[i], player->getTotalSpells(i));
        }
        ImGui::Text((" " + std::to_string(slots[i])).c_str());
        if (ImGui::ArrowButton(("##downslots" + std::to_string(i)).c_str(), ImGuiDir::ImGuiDir_Down) && slots[i])
        {
            slots[i]--;
        }
        ImGui::EndGroup();

        if (i != 7)
        {
            ImGui::SameLine();
        }
    }

    player->setRemainingSpellSlots(slots);
}
