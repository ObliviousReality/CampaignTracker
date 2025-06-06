#include "BioElement.hpp"

#include "imgui.h"

#include <sstream>

void BioElement::draw()
{
    auto * player = CTCore::Get()->getCreatureFromId<Player>(playerId, CreatureType::Player);
    const auto race = Core::getRaceString(player->getRaceType());
    const auto clas = Core::getClassString(player->getClassType());

    const auto alignment = Core::getAlignmentString(player->getAlignment());
    ImGui::Text("Level: %i", player->getLevel());
    ImGui::Text("Race: %s", race.c_str());
    ImGui::Text("Class: %s", clas.c_str());
    ImGui::Text("Alignment: %s", alignment.c_str());

    ImGui::SeparatorText("Abilities");
    auto * ab = player->getAbilities();
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
        const auto val = player->getSavingThrowModifier(at);
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
    auto hp = player->getHitPoints();
    auto maxHp = player->getHitPointsMax();

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

    player->setHitPoints(hp);
    int tempHp = player->getTempHitPoints();

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

    player->setTempHitPoint(tempHp);

    ImGui::PopItemFlag();
    ImGui::SameLine();
    ImGui::Text("/ %i", maxHp);

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

    ImGui::SeparatorText("Passives");
    auto * passives = player->getPassives();
    ImGui::Text(("Perception: " + std::to_string(passives->perception)).c_str());
    ImGui::Text(("Investigation: " + std::to_string(passives->investigation)).c_str());
    ImGui::Text(("Insight: " + std::to_string(passives->insight)).c_str());

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

    bool addedExtraValues = false;

    std::stringstream conditionStream;
    int count = 0;
    for (const auto con : player->getConditions())
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
        ImGui::Text(conditionStream.str().c_str());
    }

    count = 0;
    std::stringstream immunityStream;
    for (const auto con : player->getConditionImmunities())
    {
        if (count++)
        {
            immunityStream << ',';
        }
        immunityStream << Core::getConditionString(con).c_str();
    }
    for (const auto dt : player->getDamageTypeImmunities())
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
        ImGui::Text(immunityStream.str().c_str());
    }

    count = 0;

    std::stringstream resistanceStream;
    for (const auto dt : player->getResistances())
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
        ImGui::Text(resistanceStream.str().c_str());
    }

    count = 0;

    std::stringstream senseStream;
    for (const auto sense : player->getSenses())
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
        ImGui::Text(senseStream.str().c_str());
    }

    if (!addedExtraValues)
    {
        ImGui::SeparatorText("");
    }
}
