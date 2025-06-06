#pragma once

#include "Frame.hpp"

#include "core/Core.hpp"

#include "Frames/TabBarFrame.hpp"
#include "Frames/TitleBarFrame.hpp"

#include <memory>
#include <vector>

class PlayerFrame;
class MonsterFrame;

class MainFrame : public Frame
{
public:
    MainFrame();
    virtual void update() override;
    virtual void render() override;
    virtual const std::string getName() override;

    void createPlayerFrame(CreatureId playerId);

    void createMonsterFrame(CreatureId monsterId);

private:
    bool open = false;
    bool useWorkArea = false;
    bool closePressed = false;
    std::unique_ptr<TitleBarFrame> titleBar;
    std::unique_ptr<TabBarFrame> tabBar;
    std::vector<PlayerFrame *> playerFrames;
    std::vector<MonsterFrame *> monsterFrames;
};
