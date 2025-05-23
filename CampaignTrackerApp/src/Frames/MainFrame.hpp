#pragma once

#include "Frame.hpp"

#include "Frames/TitleBarFrame.hpp"

#include <memory>
#include <set>

class PlayerFrame;
class Player;

class MainFrame : public Frame
{
public:
    MainFrame();
    virtual void update() override;
    virtual void render() override;
    virtual const std::string getName() override;

    void createPlayerFrame(Player * p);

private:
    bool open = false;
    bool useWorkArea = false;
    bool closePressed = false;
    std::unique_ptr<TitleBarFrame> titleBar;
    std::set<PlayerFrame *> playerFrames;
};