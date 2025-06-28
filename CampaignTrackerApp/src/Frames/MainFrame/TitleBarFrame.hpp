#pragma once

#include "Frames/Frame.hpp"

#include <imgui.h>

class TitleBarFrame : public Frame
{
public:
    void update() override;
    void render() override;

    const ImVec2 getSize() const { return titleBarSize; }

private:
    bool diceWellOpen = false; // TODO: Move to ApplicationManager
    bool logOpen = false;
    bool showEnvironment = true;
    bool editMode = false;
    ImVec2 titleBarSize;
};