#pragma once

#include "Frame.hpp"

#include "core/Core.hpp"

#include "Frames/TabBarFrame.hpp"
#include "Frames/TitleBarFrame.hpp"

#include <memory>
#include <vector>

class CharacterFrame;
class MonsterFrame;

class MainFrame : public Frame
{
public:
    MainFrame();
    virtual void update() override;
    virtual void render() override;
    virtual const std::string getName() override;

    void createCharacterFrame(EntityId playerId);

    void createMonsterFrame(EntityId monsterId);

private:
    bool open = false;
    bool useWorkArea = false;
    bool closePressed = false;
    std::unique_ptr<TitleBarFrame> titleBar;
    std::unique_ptr<TabBarFrame> tabBar;
    std::vector<CharacterFrame *> characterFrames;
    std::vector<MonsterFrame *> monsterFrames;
};
