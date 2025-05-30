#pragma once

class ApplicationManager
{
public:
    static ApplicationManager * Get()
    {
        static ApplicationManager * instance = new ApplicationManager();
        return instance;
    }

    const bool isAppRunning() const { return appRunning; }

    void setAppRunning(const bool newState) { appRunning = newState; }

private:
    ApplicationManager() {}

    static ApplicationManager * appManager;

    bool appRunning = true;
};

