#include "MonsterBioElement.hpp"

#include "entities/Monster.hpp"

#include "imgui.h"

void MonsterBioElement::drawCoreInfo()
{
    auto * monster = CTCore::Get()->getMonsterFromId(getEntityId());

    const auto monsterTypeStr = Core::getMonsterTypeString(monster->getMonsterType());

    const auto alignment = Core::getAlignmentString(monster->getAlignment());
    ImGui::Text("Challenge Rating: %i", monster->getChallengeRating());
    ImGui::Text("Type: %s", monsterTypeStr.c_str());
    ImGui::Text("Alignment: %s", alignment.c_str());
}

void MonsterBioElement::drawStats()
{
    auto * monster = CTCore::Get()->getMonsterFromId(getEntityId());

    ImGui::SeparatorText("Stats");

    ImGui::Button(("Init\n +" + std::to_string(monster->getInitiative())).c_str());
    ImGui::SameLine();
    ImGui::Button(("Prof\n +" + std::to_string(monster->getProficiency())).c_str());
    ImGui::SameLine();
    ImGui::Button((" AC \n " + std::to_string(monster->getAC())).c_str());
    ImGui::SameLine();
    ImGui::Button(("Speed\n " + std::to_string(monster->getSpeed()) + "ft").c_str());
}
