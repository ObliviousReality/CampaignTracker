#include "BioElement.hpp"

#include "entities/Creature.hpp"

#include "imgui.h"

#include <sstream>

void BioElement::draw()
{
    drawCoreInfo();
    drawAbilities();
    drawSavingThrows();
    drawHitPoints();
    drawStats();
    drawPassives();
    drawSpells();
    drawOtherDetails();
}

void BioElement::drawAbilities()
{
    ImGui::SeparatorText("Abilities");
    auto * c = static_cast<Creature *>(CTCore::Get()->getEntity(creatureId, entityType));

    auto * ab = c->getAbilities();
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
}

void BioElement::drawSavingThrows()
{
    ImGui::SeparatorText("Saving Throws");
    auto * c = static_cast<Creature *>(CTCore::Get()->getEntity(creatureId, entityType));

    auto addSavingThrow = [&](const AbilityType at)
    {
        const auto val = c->getSavingThrowModifier(at);
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
}

void BioElement::drawHitPoints()
{
    auto * c = static_cast<Creature *>(CTCore::Get()->getEntity(creatureId, entityType));

    ImGui::SeparatorText("Hit Points");
    auto hp = c->getHitPoints();
    auto maxHp = c->getHitPointsMax();

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

    c->setHitPoints(hp);
    int tempHp = c->getTempHitPoints();

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

    c->setTempHitPoint(tempHp);

    ImGui::PopItemFlag();
    ImGui::SameLine();
    ImGui::Text("/ %i", maxHp);
}

void BioElement::drawPassives()
{
    auto * c = static_cast<Creature *>(CTCore::Get()->getEntity(creatureId, entityType));

    ImGui::SeparatorText("Passives");
    auto * passives = c->getPassives();
    ImGui::Text(("Perception: " + std::to_string(passives->perception)).c_str());
    ImGui::Text(("Investigation: " + std::to_string(passives->investigation)).c_str());
    ImGui::Text(("Insight: " + std::to_string(passives->insight)).c_str());
}

void BioElement::drawOtherDetails()
{
    auto * c = static_cast<Creature *>(CTCore::Get()->getEntity(creatureId, entityType));

    bool addedExtraValues = false;

    std::stringstream conditionStream;
    int count = 0;
    for (const auto con : c->getConditions())
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
    for (const auto con : c->getConditionImmunities())
    {
        if (count++)
        {
            immunityStream << ',';
        }
        immunityStream << Core::getConditionString(con).c_str();
    }
    for (const auto dt : c->getDamageTypeImmunities())
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
    for (const auto dt : c->getResistances())
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
    for (const auto sense : c->getSenses())
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
