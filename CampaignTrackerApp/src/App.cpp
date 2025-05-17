#include "Core/Core.hpp"

#include "Frames/MainFrame.hpp"

#include "Render/Win32/WinWindow.hpp"

#include "entities/Player.hpp"

#include <array>
#include <iostream>
#include <map>
#include <memory>

void printDetails(Player * p)
{
    const auto race = Core::getRaceString(p->getRaceType());
    const auto clas = Core::getClassString(p->getClassType());

    const auto alignment = Core::getAlignmentString(p->getAlignment());

    printf("%s (%s)\n", p->getName().c_str(), p->getHumanName().c_str());
    printf("%s/%s/%i/%s\n", race.c_str(), clas.c_str(), p->getLevel(), alignment.c_str());
    printf("STR DEX CON INT WIS CHA\n");
    auto * abilities = p->getAbilities();
    printf(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        abilities->getModifier(AbilityType::Strength),
        abilities->getModifier(AbilityType::Dexterity),
        abilities->getModifier(AbilityType::Constitution),
        abilities->getModifier(AbilityType::Intelligence),
        abilities->getModifier(AbilityType::Wisdom),
        abilities->getModifier(AbilityType::Charisma));

    printf("STR DEX CON INT WIS CHA\n");
    printf(
        "+%i  +%i  +%i  +%i  +%i  +%i\n",
        p->getSavingThrowModifier(AbilityType::Strength),
        p->getSavingThrowModifier(AbilityType::Dexterity),
        p->getSavingThrowModifier(AbilityType::Constitution),
        p->getSavingThrowModifier(AbilityType::Intelligence),
        p->getSavingThrowModifier(AbilityType::Wisdom),
        p->getSavingThrowModifier(AbilityType::Charisma));

    printf("%i (%i) / %i\n", p->getHitPoints(), p->getTempHitPoints(), p->getHitPointsMax());

    printf("Init / Insp / Prof / AC\n");
    printf(
        "+%i      %s    +%i    %i\n",
        p->getInitiative(),
        p->hasInspiration() ? "yes" : "no ",
        p->getProficiency(),
        p->getAC());

    printf("PER / INV / INS  SPEED\n");
    auto * passives = p->getPassives();
    printf(
        " %i   %i   %i        %ift\n",
        passives->perception,
        passives->investigation,
        passives->insight,
        p->getSpeed());

    printf(" 1 2 3 4 5 6 7 8\n");
    for (const auto slot : p->getRemainingSpellSlots())
    {
        printf(" %i", slot);
    }
    printf("\n");
    printf("Conditions:\n");
    for (const auto con : p->getConditions())
    {
        printf("%s, ", Core::getConditionString(con).c_str());
    }
    printf("\n");
    printf("Immunities:\n");
    for (const auto con : p->getConditionImmunities())
    {
        printf("%s, ", Core::getConditionString(con).c_str());
    }
    for (const auto dt : p->getDamageTypeImmunities())
    {
        printf("%s, ", Core::getDamageTypeString(dt).c_str());
    }
    printf("\n");
    printf("Resistances:\n");
    for (const auto res : p->getResistances())
    {
        printf("%s, ", Core::getDamageTypeString(res).c_str());
    }
    printf("\n");
    printf("Senses:\n");
    for (const auto sense : p->getSenses())
    {
        printf("%s, ", Core::getSenseString(sense).c_str());
    }
    printf("\n");

    printf("Skills:\n");
    auto printSkill = [&p](const SkillType st)
    {
        const auto skill = p->getSkill(st);
        std::string end;
        if (p->hasAdvantage(st) == p->hasDisadvantage(st))
        {
            end = "";
        }
        else if (p->hasAdvantage(st))
        {
            end = "+Adv";
        }
        else
        {
            end = "-Dvd";
        }
        printf("%s: %c%i %s\n", Core::getSkillString(st).c_str(), skill >= 0 ? '+' : '-', skill, end.c_str());
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

int main()
{
    std::unique_ptr<CTCore> core = std::make_unique<CTCore>();
    CTCore::PrintHelloWorld();

    auto p = core->createPlayer(
        "Berthog",
        ClassType::Warlock,
        RaceType::Dwarf,
        "Tom",
        8,
        { MoralityType::Good, OrderType::Lawful });

    p->addSense(SenseType::Darkvision);
    p->setAC(17);
    p->addResistance(DamageType::Poison);
    p->setTempHitPoint(5);

    p->setAbilities({ 20, 17, 18, 15, 14, 15 });

    p->setTaggedSkills({ SkillType::AnimalHandling, SkillType::Deception, SkillType::Perception, SkillType::Survival });

    p->setTaggedSkill(SkillType::Investigation, 2);

    p->setTaggedSavingThrows({ AbilityType::Wisdom, AbilityType::Charisma });

    p->setDisadvantage(SkillType::Stealth, true);

    p->setSpellSlots({ 0, 0, 0, 2, 0, 0, 0, 0 });

    p->generateSkills();
    printDetails(p);

    printf("\n\n\n\n");

    auto p2 = core->createPlayer(
        "Elysia Autumnfire",
        ClassType::Wizard,
        RaceType::Elf,
        "Tom",
        8,
        { MoralityType::Good, OrderType::Lawful });
    p2->addSense(SenseType::Darkvision);
    p2->setAC(12);

    p2->setAbilities({ 10, 14, 11, 18, 14, 13 });

    p2->setTaggedSkills({ SkillType::Arcana,
                          SkillType::Athletics,
                          SkillType::Medicine,
                          SkillType::Perception,
                          SkillType::Performance,
                          SkillType::Survival });

    p2->setTaggedSavingThrows({ AbilityType::Intelligence, AbilityType::Wisdom });

    p2->setSpellSlots({ 4, 3, 3, 2, 0, 0, 0, 0 });
    p2->generateSkills();
    printDetails(p);

    auto p3 = core->createPlayer(
        "Gulthandor Jones",
        ClassType::Ranger,
        RaceType::HalfElf,
        "Tom",
        4,
        { MoralityType::Neutral, OrderType::Neutral });
    p3->addSense(SenseType::Darkvision);
    p3->setAC(13);

    p3->setAbilities({ 13, 14, 8, 12, 15, 16 });
    p3->setTaggedSkills({ SkillType::AnimalHandling,
                          SkillType::Athletics,
                          SkillType::Deception,
                          SkillType::History,
                          SkillType::Investigation,
                          SkillType::Stealth,
                          SkillType::Survival });

    p3->setTaggedSavingThrows({ AbilityType::Strength, AbilityType::Dexterity });
    p3->setSpellSlots({ 3, 0, 0, 0, 0, 0, 0, 0 });
    p3->generateSkills();

    auto p4 = core->createPlayer(
        "Natalie Stormwind",
        ClassType::Rogue,
        RaceType::Human,
        "Tom",
        2,
        { MoralityType::Good, OrderType::Chaotic });
    p4->setAC(13);
    p4->setAbilities({ 13, 15, 14, 17, 15, 15 });
    p4->setTaggedSkills(
        { SkillType::Athletics, SkillType::Deception, SkillType::Investigation, SkillType::Persuasion });
    p4->setTaggedSkills({ SkillType::Perception, SkillType::Stealth }, 2);
    p4->setTaggedSavingThrows({ AbilityType::Dexterity, AbilityType::Intelligence });
    p4->generateSkills();

    std::unique_ptr<WinWindow> window = std::make_unique<WinWindow>();
    window->createWindow();
    window->initImGui();

    auto mainWindow = std::make_unique<MainFrame>();

    mainWindow->createPlayerFrame(p);
    mainWindow->createPlayerFrame(p2);
    mainWindow->createPlayerFrame(p3);
    mainWindow->createPlayerFrame(p4);

    bool running = true;
    int sliderVal = 0;
    while (running)
    {
        const auto x = window->pollUpdates();
        if (x)
        {
            running = false;
            break;
        }
        window->startFrame();
        mainWindow->render();
#if defined(DEBUG)
        ImGui::ShowDemoWindow();
#endif
        window->endFrame();
    }

    //std::cin.get();
    return 0;
}