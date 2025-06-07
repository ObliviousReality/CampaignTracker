#pragma once

#include "Frame.hpp"

#include "core/Core.hpp"

#include <memory>

class MonsterBioElement;
class NotesElement;
class SkillsElement;

class MonsterFrame : public Frame
{
public:
    MonsterFrame(CreatureId _id);
    void update() override {}
    void render() override;
    const std::string getName() override { return {}; }

private:
    CreatureId monsterId;

    std::unique_ptr<MonsterBioElement> bioElement;
    std::unique_ptr<SkillsElement> skillsElement;
    std::unique_ptr<NotesElement> notesElement;
};