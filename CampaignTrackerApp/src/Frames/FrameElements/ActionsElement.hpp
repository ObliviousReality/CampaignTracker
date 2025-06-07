#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class ActionsElement : public FrameElement
{
public:
    ActionsElement(CreatureId cId) : id(cId) {}

    void update() override {}
    void draw() override;

private:
    CreatureId id;
};