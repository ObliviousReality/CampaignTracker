#include "PlayerFrame.hpp"

#include "imgui.h"

void PlayerFrame::update() {}

void PlayerFrame::render()
{
    ImGui::BeginChild(player->getName().c_str(), ImVec2(256, ImGui::GetContentRegionAvail().y));
    const auto race = Core::getRaceString(player->getRaceType());
    const auto clas = Core::getClassString(player->getClassType());

    const auto alignment = Core::getAlignmentString(player->getAlignment());
    const auto titleText = player->getName() + " (" + (player->getHumanName()) + ")";
    ImGui::SeparatorText(titleText.c_str());
    ImGui::Text("Level: %i", player->getLevel());
    ImGui::Text("Race: %s", race.c_str());
    ImGui::Text("Class: %s", clas.c_str());
    ImGui::Text("Alignment: %s", alignment.c_str());

    ImGui::SeparatorText("Abilities");
    auto * ab = player->getAbilities();
    auto addAbility = [](const AbilityType at, const Abilities * ab)
    {
        const auto val = ab->getModifier(at);
        const auto text = Core::getAbilityShortString(at) + "\n " + (val >= 0 ? '+' : '-') + std::to_string(val);
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
        const auto text = Core::getAbilityShortString(at) + "\n" + (val >= 0 ? '+' : '-') + std::to_string(val);
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

    ImGui::Text("Init / Insp / Prof / AC\n");
    ImGui::Text(
        "+%i      %s    +%i    %i\n",
        player->getInitiative(),
        player->hasInspiration() ? "yes" : "no ",
        player->getProficiency(),
        player->getAC());

    ImGui::Text("PER / INV / INS  SPEED\n");
    auto * passives = player->getPassives();
    ImGui::Text(
        " %i   %i   %i        %ift\n",
        passives->perception,
        passives->investigation,
        passives->insight,
        player->getSpeed());

    ImGui::Text("\n");
    ImGui::Text(" 1 2 3 4 5 6 7 8\n");
    const auto & slots = player->getRemainingSpellSlots();
    {
        ImGui::Text(
            " %i %i %i %i %i %i %i %i",
            slots[0],
            slots[1],
            slots[2],
            slots[3],
            slots[4],
            slots[5],
            slots[6],
            slots[7]);
    }
    ImGui::Text("\n");
    ImGui::Text("Conditions:\n");
    for (const auto con : player->getConditions())
    {
        ImGui::Text("%s, ", Condition::getConditionString(con).c_str());
    }
    ImGui::Text("\n");
    ImGui::Text("Immunities:\n");
    for (const auto con : player->getConditionImmunities())
    {
        ImGui::Text("%s, ", Condition::getConditionString(con).c_str());
    }
    for (const auto dt : player->getDamageTypeImmunities())
    {
        ImGui::Text("%s, ", Core::getDamageTypeString(dt).c_str());
    }
    ImGui::Text("\n");
    ImGui::Text("Resistances:\n");
    for (const auto res : player->getResistances())
    {
        ImGui::Text("%s, ", Core::getDamageTypeString(res).c_str());
    }
    ImGui::Text("\n");
    ImGui::Text("Senses:\n");
    for (const auto sense : player->getSenses())
    {
        ImGui::Text("%s, ", Core::getSenseString(sense).c_str());
    }
    ImGui::Text("\n");

    ImGui::Text("Skills:\n");
    auto printSkill = [&](const SkillType st)
    {
        const auto skill = player->getSkill(st);
        std::string end;
        if (player->hasAdvantage(st) == player->hasDisadvantage(st))
        {
            end = "";
        }
        else if (player->hasAdvantage(st))
        {
            end = "+Adv";
        }
        else
        {
            end = "-Dvd";
        }
        ImGui::Text("%s: %c%i %s\n", Core::getSkillString(st).c_str(), skill >= 0 ? '+' : '-', skill, end.c_str());
    };
    printSkill(SkillType::Acrobatics);
    printSkill(SkillType::AnimalHandling);
    printSkill(SkillType::Arcana);
    printSkill(SkillType::Athletics);
    printSkill(SkillType::Deception);
    printSkill(SkillType::History);
    printSkill(SkillType::Deception);
    printSkill(SkillType::History);
    printSkill(SkillType::Insight);
    printSkill(SkillType::Intimidation);
    printSkill(SkillType::Investigation);
    printSkill(SkillType::Medicine);
    printSkill(SkillType::Nature);
    printSkill(SkillType::Perception);
    printSkill(SkillType::Performance);
    printSkill(SkillType::Persuasion);
    printSkill(SkillType::Religion);
    printSkill(SkillType::SleightOfHand);
    printSkill(SkillType::Stealth);
    printSkill(SkillType::Survival);
    ImGui::EndChild();
}

const std::string PlayerFrame::getName() { return player->getName(); }
