#pragma once

#include "FrameElement.hpp"

constexpr const int TextBoxSize = 1024 * 16;

class NotesElement : public FrameElement
{
public:
    NotesElement() {}
    void update() override {}
    void draw() override;

private:
    char text[TextBoxSize] = "";
};