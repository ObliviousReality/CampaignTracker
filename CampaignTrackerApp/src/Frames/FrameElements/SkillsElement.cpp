#include "SkillsElement.hpp"

#include "imgui.h"

void SkillsElement::draw()
{
    auto * player = CTCore::Get()->getCreatureFromId<Player>(id, CreatureType::Player);
    ImGui::SeparatorText("Skills");
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
}
