#include "WindowManager.hpp"

WindowManager::WindowManager()
{
    mainFrame = std::make_unique<MainFrame>();
    for (int i = 0; i < static_cast<int>(CreatureType::NUM_CREATURES); ++i)
    {
        CreatureType t = static_cast<CreatureType>(i);
        visibleBrowsers[t] = false;
        entityBrowsers[t] = std::make_unique<EntityBrowser>(t, visibleBrowsers[t]);
    }
}

void WindowManager::update()
{
    mainFrame->update();
    for (const auto & entry : visibleBrowsers)
    {
        if (entry.second)
        {
            entityBrowsers[entry.first]->update();
        }
    }
}

void WindowManager::render()
{
    mainFrame->render();
    for (const auto & entry : visibleBrowsers)
    {
        if (entry.second)
        {
            entityBrowsers[entry.first]->render();
        }
    }
}
