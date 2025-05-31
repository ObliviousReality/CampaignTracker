#include "TabBarFrame.hpp"

#include "Application/ApplicationManager.hpp"

#include "imgui.h"

void TabBarFrame::render()
{
    ImGui::BeginGroup();
    {
        ImGui::Button("Save", { buttonWidth, height });
        ImGui::SameLine();
        ImGui::Button("Load", { buttonWidth, height });
        ImGui::SameLine();

        // Width of buttons before + (width of buttons after + 0.5)
        const auto modeIndicatorWidth = ImGui::GetWindowWidth() - ((2.0f * buttonWidth) + (4.0f * buttonWidth));
        ImGui::BeginDisabled();
        ImGui::Button(mode ? "Mode One" : "Mode Two", { modeIndicatorWidth, height });
        ImGui::EndDisabled();
        ImGui::SameLine();
        auto & style = ImGui::GetStyle();
        if (ImGui::Button("Switch Mode", { 2 * buttonWidth, height }))
        {
            mode = !mode;
        }
        ImGui::SameLine();
        if (ImGui::Button("Close", { buttonWidth, height }))
        {
            ApplicationManager::Get()->setAppRunning(false);
        }
        ImGui::EndGroup();
    }
}
