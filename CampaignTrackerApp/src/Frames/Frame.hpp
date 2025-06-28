#pragma once

#include <string>

class Frame
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
};