#include "TitleBarFrame.hpp"

#include "imgui.h"

void TitleBarFrame::update() {}

void TitleBarFrame::render()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Close", "Alt+F4")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

const std::string TitleBarFrame::getName() { return std::string(); }
