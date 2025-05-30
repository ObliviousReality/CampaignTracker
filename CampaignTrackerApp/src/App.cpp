#include "Application/ApplicationManager.hpp"

#include "Core/Core.hpp"

#include "Frames/MainFrame.hpp"

#include "Render/Win32/WinWindow.hpp"

#include "entities/Player.hpp"

#include <memory>

int main()
{
    auto core = std::make_unique<CTCore>();
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

    int sliderVal = 0;
    while (ApplicationManager::Get()->isAppRunning())
    {
        window->startFrame();
        mainWindow->render();
#if defined(DEBUG)
        ImGui::ShowDemoWindow();
#endif
        window->endFrame();
        window->pollUpdates();
    }

    //std::cin.get();
    return 0;
}