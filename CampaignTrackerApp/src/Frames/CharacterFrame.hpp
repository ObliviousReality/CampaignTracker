#pragma once

#include "Frames/Frame.hpp"

#include "core/Core.hpp"

#include <memory>

class CharacterBioElement;
class NotesElement;
class SkillsElement;

class CharacterFrame : public Frame
{
public:
    CharacterFrame(EntityId id);

    void update() override {}
    void render() override;

    const std::string getName() override;

private:
    EntityId playerId;

    std::unique_ptr<CharacterBioElement> bioElement;
    std::unique_ptr<SkillsElement> skillsElement;
    std::unique_ptr<NotesElement> notesElement;
};
