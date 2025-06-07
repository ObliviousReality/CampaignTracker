#pragma once

#include "Frames/Frame.hpp"

#include "core/Core.hpp"

#include <memory>

class PlayerBioElement;
class NotesElement;
class SkillsElement;

class PlayerFrame : public Frame
{
public:
    PlayerFrame(CreatureId id);

    void update() override {}
    void render() override;

    const std::string getName() override;

private:
    CreatureId playerId;

    std::unique_ptr<PlayerBioElement> bioElement;
    std::unique_ptr<SkillsElement> skillsElement;
    std::unique_ptr<NotesElement> notesElement;
};
