#pragma once

class Window
{
public:
    Window() {}

    virtual void createWindow() = 0;
    virtual void initImGui() = 0;
    virtual bool pollUpdates() = 0;
    virtual void startFrame() = 0;
    virtual void endFrame() = 0;
};