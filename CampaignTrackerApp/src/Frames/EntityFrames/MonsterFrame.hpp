#pragma once

#include "Frames/Frame.hpp"

#include "core/Core.hpp"

#include <memory>

class ActionsElement;
class MonsterBioElement;
class SkillsElement;

class MonsterFrame : public Frame
{
public:
    MonsterFrame(EntityId _id);
    void update() override {}
    void render() override;

private:
    EntityId monsterId;

    std::unique_ptr<MonsterBioElement> bioElement;
    std::unique_ptr<SkillsElement> skillsElement;
    std::unique_ptr<ActionsElement> actionsElement;
};
