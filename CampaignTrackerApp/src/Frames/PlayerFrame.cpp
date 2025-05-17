#include "PlayerFrame.hpp"

#include "imgui.h"

void PlayerFrame::update() {}

void PlayerFrame::render()
{
    ImGui::BeginChild(player->getName().c_str(), ImVec2(256, ImGui::GetContentRegionAvail().y));
    const auto race = Core::getRaceString(player->getRaceType());
    const auto clas = Core::getClassString(player->getClassType());

    const auto alignment = Core::getAlignmentString(player->getAlignment());

    ImGui::Text("%s (%s)\n", player->getName().c_str(), player->getHumanName().c_str());
    ImGui::Text("%s/%s/%i/%s\n", race.c_str(), clas.c_str(), player->getLevel(), alignment.c_str());
    ImGui::Text("STR DEX CON INT WIS CHA\n");
    auto * abilities = player->getAbilities();
    ImGui::Text(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        abilities->getModifier(AbilityType::Strength),
        abilities->getModifier(AbilityType::Dexterity),
        abilities->getModifier(AbilityType::Constitution),
        abilities->getModifier(AbilityType::Intelligence),
        abilities->getModifier(AbilityType::Wisdom),
        abilities->getModifier(AbilityType::Charisma));

    ImGui::Text("STR DEX CON INT WIS CHA\n");
    ImGui::Text(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        player->getSavingThrowModifier(AbilityType::Strength),
        player->getSavingThrowModifier(AbilityType::Dexterity),
        player->getSavingThrowModifier(AbilityType::Constitution),
        player->getSavingThrowModifier(AbilityType::Intelligence),
        player->getSavingThrowModifier(AbilityType::Wisdom),
        player->getSavingThrowModifier(AbilityType::Charisma));

    ImGui::Text("\n");
    ImGui::Text("%i (%i) / %i\n", player->getHitPoints(), player->getTempHitPoints(), player->getHitPointsMax());
    ImGui::Text("\n");

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
