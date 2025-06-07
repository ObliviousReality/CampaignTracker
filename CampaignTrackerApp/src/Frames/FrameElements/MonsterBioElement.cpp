#include "MonsterBioElement.hpp"

#include "entities/Monster.hpp"

#include "imgui.h"

#include <sstream>

void MonsterBioElement::draw()
{
    auto * monster = CTCore::Get()->getMonsterFromId(monsterId);

    const auto monsterTypeStr = Core::getMonsterTypeString(monster->getMonsterType());

    const auto alignment = Core::getAlignmentString(monster->getAlignment());
    ImGui::Text("Challenge Rating: %i", monster->getChallengeRating());
    ImGui::Text("Type: %s", monsterTypeStr.c_str());
    ImGui::Text("Alignment: %s", alignment.c_str());

    ImGui::SeparatorText("Abilities");
    auto * ab = monster->getAbilities();
    auto addAbility = [](const AbilityType at, const Abilities * ab)
    {
        const auto val = ab->getModifier(at);
        const auto text = Core::getAbilityShortString(at) + "\n " + (val >= 0 ? '+' : '-') + std::to_string(abs(val));
        ImGui::Button(text.c_str());
        if (at != AbilityType::Charisma)
        {
            ImGui::SameLine();
        }
    };

    addAbility(AbilityType::Strength, ab);
    addAbility(AbilityType::Dexterity, ab);
    addAbility(AbilityType::Constitution, ab);
    addAbility(AbilityType::Intelligence, ab);
    addAbility(AbilityType::Wisdom, ab);
    addAbility(AbilityType::Charisma, ab);

    ImGui::SeparatorText("Saving Throws");

    auto addSavingThrow = [&](const AbilityType at)
    {
        const auto val = monster->getSavingThrowModifier(at);
        const auto text = Core::getAbilityShortString(at) + "\n" + (val >= 0 ? '+' : '-') + std::to_string(abs(val));
        ImGui::Button(text.c_str());
        if (at != AbilityType::Charisma)
        {
            ImGui::SameLine();
        }
    };

    addSavingThrow(AbilityType::Strength);
    addSavingThrow(AbilityType::Dexterity);
    addSavingThrow(AbilityType::Constitution);
    addSavingThrow(AbilityType::Intelligence);
    addSavingThrow(AbilityType::Wisdom);
    addSavingThrow(AbilityType::Charisma);

    ImGui::SeparatorText("Hit Points");
    auto hp = monster->getHitPoints();
    auto maxHp = monster->getHitPointsMax();

    ImGui::PushItemFlag(ImGuiItemFlags_ButtonRepeat, true);

    if (ImGui::ArrowButton("##lefthp", ImGuiDir::ImGuiDir_Left) && (hp > 0))
    {
        int shiftAmount = 1;
        if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftShift))
        {
            shiftAmount = 10;
        }
        else if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftCtrl))
        {
            shiftAmount = 5;
        }
        hp -= shiftAmount;
        hp = std::max(hp, 0);
    }
    ImGui::SameLine();
    ImGui::Text("%i", hp);
    ImGui::SameLine();
    if (ImGui::ArrowButton("##rightp", ImGuiDir::ImGuiDir_Right) && (hp < maxHp))
    {
        int shiftAmount = 1;
        if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftShift))
        {
            shiftAmount = 10;
        }
        else if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftCtrl))
        {
            shiftAmount = 5;
        }
        hp += shiftAmount;
        hp = std::min(hp, maxHp);
    }

    monster->setHitPoints(hp);
    int tempHp = monster->getTempHitPoints();

    ImGui::SameLine();
    if (ImGui::ArrowButton("##leftthp", ImGuiDir::ImGuiDir_Left) && (tempHp > 0))
    {
        int shiftAmount = 1;
        if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftShift))
        {
            shiftAmount = 10;
        }
        else if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftCtrl))
        {
            shiftAmount = 5;
        }
        tempHp -= shiftAmount;
        tempHp = std::max(tempHp, 0);
    }
    ImGui::SameLine();
    ImGui::Text("+%i", tempHp);
    ImGui::SameLine();
    if (ImGui::ArrowButton("##rightthp", ImGuiDir::ImGuiDir_Right))
    {
        int shiftAmount = 1;
        if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftShift))
        {
            shiftAmount = 10;
        }
        else if (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftCtrl))
        {
            shiftAmount = 5;
        }
        tempHp += shiftAmount;
    }

    monster->setTempHitPoint(tempHp);

    ImGui::PopItemFlag();
    ImGui::SameLine();
    ImGui::Text("/ %i", maxHp);

    ImGui::SeparatorText("Stats");

    ImGui::Button(("Init\n +" + std::to_string(monster->getInitiative())).c_str());
    ImGui::SameLine();
    ImGui::Button(("Prof\n +" + std::to_string(monster->getProficiency())).c_str());
    ImGui::SameLine();
    ImGui::Button((" AC \n " + std::to_string(monster->getAC())).c_str());
    ImGui::SameLine();
    ImGui::Button(("Speed\n " + std::to_string(monster->getSpeed()) + "ft").c_str());

    ImGui::SeparatorText("Passives");
    auto * passives = monster->getPassives();
    ImGui::Text(("Perception: " + std::to_string(passives->perception)).c_str());
    ImGui::Text(("Investigation: " + std::to_string(passives->investigation)).c_str());
    ImGui::Text(("Insight: " + std::to_string(passives->insight)).c_str());

    bool addedExtraValues = false;

    std::stringstream conditionStream;
    int count = 0;
    for (const auto con : monster->getConditions())
    {
        if (count++)
        {
            conditionStream << ',';
        }
        conditionStream << Core::getConditionString(con).c_str();
    }

    if (count)
    {
        addedExtraValues = true;
        ImGui::SeparatorText("Conditions");
        ImGui::TextWrapped(conditionStream.str().c_str());
    }

    count = 0;
    std::stringstream immunityStream;
    for (const auto con : monster->getConditionImmunities())
    {
        if (count++)
        {
            immunityStream << ',';
        }
        immunityStream << Core::getConditionString(con).c_str();
    }
    for (const auto dt : monster->getDamageTypeImmunities())
    {
        if (count++)
        {
            immunityStream << ',';
        }
        immunityStream << Core::getDamageTypeString(dt).c_str();
    }

    if (count)
    {
        addedExtraValues = true;
        ImGui::SeparatorText("Immunities");
        ImGui::TextWrapped(immunityStream.str().c_str());
    }

    count = 0;

    std::stringstream resistanceStream;
    for (const auto dt : monster->getResistances())
    {
        if (count++)
        {
            resistanceStream << ',';
        }
        resistanceStream << Core::getDamageTypeString(dt).c_str();
    }

    if (count)
    {
        ImGui::SeparatorText("Resistances");
        ImGui::TextWrapped(resistanceStream.str().c_str());
    }

    count = 0;

    std::stringstream senseStream;
    for (const auto sense : monster->getSenses())
    {
        if (count++)
        {
            senseStream << ',';
        }
        senseStream << Core::getSenseString(sense).c_str();
    }

    if (count)
    {
        addedExtraValues = true;
        ImGui::SeparatorText("Senses");
        ImGui::TextWrapped(senseStream.str().c_str());
    }

    if (!addedExtraValues)
    {
        ImGui::SeparatorText("");
    }
}
