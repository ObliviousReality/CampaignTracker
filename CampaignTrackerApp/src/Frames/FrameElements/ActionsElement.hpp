#pragma once

#include "FrameElement.hpp"

#include "core/Core.hpp"

class ActionsElement : public FrameElement
{
public:
    ActionsElement(EntityId cId) : id(cId) {}

    void update() override {}
    void draw() override;

private:
    EntityId id;
};
