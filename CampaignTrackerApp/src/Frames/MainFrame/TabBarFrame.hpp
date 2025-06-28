#pragma once

#include "Frames/Frame.hpp"

class TabBarFrame : public Frame
{
public:
    virtual void update() override {}
    virtual void render() override;

private:
    float height = 50.0f;
    float buttonWidth = 50.0f;

    bool mode = true;
};