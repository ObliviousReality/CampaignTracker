#include "TitleBarFrame.hpp"

#include "Application/ApplicationManager.hpp"

void TitleBarFrame::update() {}

void TitleBarFrame::render()
{
    if (ImGui::BeginMenuBar())
    {
        titleBarSize = ImGui::GetWindowSize();
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Close", "Alt+F4"))
            {
                ApplicationManager::Get()->setAppRunning(false);
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

const std::string TitleBarFrame::getName() { return std::string(); }
