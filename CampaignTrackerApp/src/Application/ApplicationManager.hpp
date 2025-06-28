#pragma once

#include "WindowManager.hpp"

#include <memory>

class ApplicationManager
{
public:
    ApplicationManager(ApplicationManager const &) = delete;
    void operator=(ApplicationManager const &) = delete;

    static ApplicationManager * Get()
    {
        static ApplicationManager * instance = new ApplicationManager();
        return instance;
    }

    const bool isAppRunning() const { return appRunning; }

    void setAppRunning(const bool newState) { appRunning = newState; }

    void update() { windowManager->update(); }
    void render() { windowManager->render(); }

    WindowManager * getWindowManager() { return windowManager.get(); }

private:
    ApplicationManager() { windowManager = std::make_unique<WindowManager>(); }

    static ApplicationManager * appManager;

    std::unique_ptr<WindowManager> windowManager;

    bool appRunning = true;
};
