#pragma once

#include "Frame.hpp"

class TabBarFrame : public Frame
{
public:
    // Inherited via Frame
    virtual void update() override {}
    virtual void render() override;
    virtual const std::string getName() override { return "Tab Bar"; }

private:
    float height = 50.0f;
    float buttonWidth = 50.0f;

    bool mode = true;
};