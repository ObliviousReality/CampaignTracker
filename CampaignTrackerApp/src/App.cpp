#include "Application/ApplicationManager.hpp"

#include "Core/Core.hpp"

#include "Frames/MainFrame.hpp"

#include "Render/Win32/WinWindow.hpp"

#include "entities/Character.hpp"

#include <memory>

int main()
{
    auto * core = CTCore::Get();
    CTCore::PrintHelloWorld();

    const auto berthogId = core->createPlayer();
    auto * berthog = core->getCreatureFromId<Player>(berthogId, CreatureType::Player);

    berthog->setName("Berthog");
    berthog->setClassType(ClassType::Warlock);
    berthog->setRaceType(RaceType::Dwarf);
    berthog->setHumanName("Tom");
    berthog->setLevel(8);
    berthog->setAlignment(MoralityType::Good, OrderType::Lawful);

    berthog->addSense(SenseType::Darkvision);
    berthog->setAC(17);
    berthog->addResistance(DamageType::Poison);
    berthog->setTempHitPoint(5);

    berthog->setAbilities({ 20, 17, 18, 15, 14, 15 });

    berthog->setTaggedSkills(
        { SkillType::AnimalHandling, SkillType::Deception, SkillType::Perception, SkillType::Survival });

    berthog->setTaggedSkill(SkillType::Investigation, 2);

    berthog->setTaggedSavingThrows({ AbilityType::Wisdom, AbilityType::Charisma });

    berthog->setDisadvantage(SkillType::Stealth, true);

    berthog->setSpellSlots({ 0, 0, 0, 2, 0, 0, 0, 0 });

    berthog->generateSkills();

    const auto elysiaId = core->createPlayer();
    auto * elysia = core->getCreatureFromId<Player>(elysiaId, CreatureType::Player);

    elysia->setName("Elysia Autumnfire");
    elysia->setClassType(ClassType::Wizard);
    elysia->setRaceType(RaceType::Elf);
    elysia->setHumanName("Tom");
    elysia->setLevel(8);
    elysia->setAlignment(MoralityType::Good, OrderType::Lawful);

    elysia->addSense(SenseType::Darkvision);
    elysia->setAC(12);

    elysia->setAbilities({ 10, 14, 11, 18, 14, 13 });

    elysia->setTaggedSkills({ SkillType::Arcana,
                              SkillType::Athletics,
                              SkillType::Medicine,
                              SkillType::Perception,
                              SkillType::Performance,
                              SkillType::Survival });

    elysia->setTaggedSavingThrows({ AbilityType::Intelligence, AbilityType::Wisdom });

    elysia->setSpellSlots({ 4, 3, 3, 2, 0, 0, 0, 0 });
    elysia->generateSkills();

    const auto gulthandorId = core->createPlayer();
    auto * gulthandor = core->getCreatureFromId<Player>(gulthandorId, CreatureType::Player);

    gulthandor->setName("Gulthandor Jones");
    gulthandor->setClassType(ClassType::Ranger);
    gulthandor->setRaceType(RaceType::HalfElf);
    gulthandor->setHumanName("Tom");
    gulthandor->setLevel(4);
    gulthandor->setAlignment(MoralityType::Neutral, OrderType::Neutral);

    gulthandor->addSense(SenseType::Darkvision);
    gulthandor->setAC(13);

    gulthandor->setAbilities({ 13, 14, 8, 12, 15, 16 });
    gulthandor->setTaggedSkills({ SkillType::AnimalHandling,
                                  SkillType::Athletics,
                                  SkillType::Deception,
                                  SkillType::History,
                                  SkillType::Investigation,
                                  SkillType::Stealth,
                                  SkillType::Survival });

    gulthandor->setTaggedSavingThrows({ AbilityType::Strength, AbilityType::Dexterity });
    gulthandor->setSpellSlots({ 3, 0, 0, 0, 0, 0, 0, 0 });
    gulthandor->generateSkills();

    const auto natalieId = core->createPlayer();
    auto * natalie = core->getCreatureFromId<Player>(natalieId, CreatureType::Player);

    natalie->setName("Natalie Stormwind");
    natalie->setClassType(ClassType::Rogue);
    natalie->setRaceType(RaceType::Human);
    natalie->setHumanName("Tom");
    natalie->setLevel(2);
    natalie->setAlignment(MoralityType::Good, OrderType::Chaotic);

    natalie->setAC(13);
    natalie->setAbilities({ 13, 15, 14, 17, 15, 15 });
    natalie->setTaggedSkills(
        { SkillType::Athletics, SkillType::Deception, SkillType::Investigation, SkillType::Persuasion });
    natalie->setTaggedSkills({ SkillType::Perception, SkillType::Stealth }, 2);
    natalie->setTaggedSavingThrows({ AbilityType::Dexterity, AbilityType::Intelligence });
    natalie->generateSkills();

    auto airElementalId = core->createMonster();
    auto * airElemental = core->getMonsterFromId(airElementalId);

    airElemental->setName("gary");
    airElemental->setMonsterTypeName("Air Elemental");
    airElemental->setChallengeRating(5);
    airElemental->setMonsterType(MonsterType::Elemental);
    airElemental->setAlignment(MoralityType::Neutral, OrderType::Neutral);
    airElemental->setAC(15);
    airElemental->setMaxHitPoints(90);
    airElemental->setSpeed(10);
    airElemental->setAbilities({ 14, 20, 14, 6, 10, 6 });
    airElemental->addResistance(DamageType::Bludgeoning);
    airElemental->addResistance(DamageType::Lightning);
    airElemental->addResistance(DamageType::Piercing);
    airElemental->addResistance(DamageType::Slashing);
    airElemental->addImmunity(DamageType::Poison);
    airElemental->addImmunity(DamageType::Thunder);
    airElemental->addImmunity(ConditionType::Exhaustion);
    airElemental->addImmunity(ConditionType::Grappled);
    airElemental->addImmunity(ConditionType::Paralysed);
    airElemental->addImmunity(ConditionType::Petrified);
    airElemental->addImmunity(ConditionType::Poisoned);
    airElemental->addImmunity(ConditionType::Prone);
    airElemental->addImmunity(ConditionType::Restrained);
    airElemental->addImmunity(ConditionType::Unconscious);

    Action * actionA = new Action();
    actionA->setName("Multiattack");
    actionA->setDescription("The elemental takes two Thunderous Slam attacks");
    actionA->setLimitType(ActionLimitType::PerDay, 2);
    airElemental->addAction(actionA);

    auto * actionB = new Action();
    actionB->setName("Thunderous Slam");
    actionB->setDescription("Melee Attack Roll: +8, reach 10ft. Hit 14 (2d8 + 5) Thunder damage.");
    actionB->setLimitType(ActionLimitType::RechargeShortRest);
    airElemental->addAction(actionB);

    auto * actionC = new Action();
    actionC->setName("Whirlwind");
    actionC->setDescription(
        "Strength Saving Throw: DC 13, one Medium or smaller creature in the elemental’s space. Failure: 24 "
        "(4d10 + 2) Thunder damage, and the target is pushed up to 20 feet straight away from the elemental "
        "and has the Prone condition. Success: Half damage only.");
    actionC->setLimitType(ActionLimitType::RechargeRoll, 4);
    airElemental->addAction(actionC);

    airElemental->addSense(SenseType::Darkvision);
    airElemental->generateSkills();

    //const auto bartId = core->createNPC();
    //auto bart = core->getNPCFromId(bartId);

    //bart->setName("Bart");
    //bart->markNPC();
    //bart->setClassType(ClassType::None);
    //bart->setRaceType(RaceType::Human);
    //bart->setLevel(1);
    //bart->setAlignment(MoralityType::Neutral, OrderType::Neutral);

    //bart->setAC(12);
    //bart->setAbilities({ 10, 10, 10, 10, 10, 10 });
    //bart->setTaggedSkills({ SkillType::Religion });
    //bart->generateSkills();

    std::unique_ptr<WinWindow> window = std::make_unique<WinWindow>();
    window->createWindow();
    window->initImGui();

    auto mainWindow = std::make_unique<MainFrame>();

    mainWindow->createPlayerFrame(berthogId);
    mainWindow->createPlayerFrame(elysiaId);
    mainWindow->createPlayerFrame(gulthandorId);
    mainWindow->createPlayerFrame(natalieId);
    mainWindow->createMonsterFrame(airElementalId);

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