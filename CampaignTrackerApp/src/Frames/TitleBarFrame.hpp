#pragma once

#include "Frame.hpp"

class TitleBarFrame : public Frame
{
public:
    void update() override;
    void render() override;
    const std::string getName() override;

private:
    bool closePressed = false;
};