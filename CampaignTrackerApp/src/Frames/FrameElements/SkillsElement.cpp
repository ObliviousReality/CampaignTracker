#include "SkillsElement.hpp"

#include "imgui.h"

void SkillsElement::draw()
{
    Creature * creature;
    switch (type)
    {
        case EntityType::Character: creature = dynamic_cast<Creature *>(CTCore::Get()->getCharacterFromId(id)); break;
        case EntityType::Monster: creature = dynamic_cast<Creature *>(CTCore::Get()->getMonsterFromId(id)); break;
        default: break;
    }
    ImGui::SeparatorText("Skills");
    auto printSkill = [&](const SkillType st)
    {
        const auto skill = creature->getSkill(st);
        std::string end;
        if (creature->hasAdvantage(st) == creature->hasDisadvantage(st))
        {
            end = "";
        }
        else if (creature->hasAdvantage(st))
        {
            end = "+Adv";
        }
        else
        {
            end = "-Dvd";
        }
        ImGui::Text(
            "%s: %c%i %s\n",
            Core::getSkillString(st).c_str(),
            skill >= 0 ? '+' : '-',
            std::abs(skill),
            end.c_str());
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
