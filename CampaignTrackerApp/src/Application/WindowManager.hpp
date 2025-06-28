#pragma once

#include "Frames/EntityBrowser/EntityBrowser.hpp"

#include "Frames/MainFrame/MainFrame.hpp"

#include <memory>
#include <vector>

class WindowManager
{
public:
    WindowManager();

    void update();
    void render();

    bool & getBrowserState(CreatureType t) { return visibleBrowsers[t]; }

private:
    std::unique_ptr<MainFrame> mainFrame;

    std::map<CreatureType, std::unique_ptr<EntityBrowser>> entityBrowsers;
    std::map<CreatureType, bool> visibleBrowsers;

    bool playerBrowserVisible = false;
};