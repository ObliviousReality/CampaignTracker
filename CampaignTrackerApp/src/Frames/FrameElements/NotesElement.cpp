#include "NotesElement.hpp"

#include "imgui.h"

void NotesElement::draw()
{
    ImGui::SeparatorText("Notes");

    auto flags = ImGuiInputTextFlags_AllowTabInput;

    ImGui::InputTextMultiline("###Notes", text, TextBoxSize, { -FLT_MIN, 500 }, flags);
}
