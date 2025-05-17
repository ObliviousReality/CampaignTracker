#pragma once

#include "Frames/Frame.hpp"

#include "entities/Player.hpp"

class PlayerFrame : public Frame
{
public:
    PlayerFrame(Player * p) : player(p) {}

    void update() override;
    void render() override;

    const std::string getName() override;

private:
    Player * player = nullptr;
};