#pragma once

#include "Frames/Frame.hpp"

#include "entities/Player.hpp"

#include <memory>

class BioElement;
class NotesElement;
class SkillsElement;

class PlayerFrame : public Frame
{
public:
    PlayerFrame(Player * p);

    void update() override {}
    void render() override;

    const std::string getName() override;

private:
    Player * player = nullptr;

    std::unique_ptr<BioElement> bioElement;
    std::unique_ptr<SkillsElement> skillsElement;
    std::unique_ptr<NotesElement> notesElement;
};
