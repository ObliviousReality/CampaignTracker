#include "MainFrame.hpp"

#include "Frames/PlayerFrame.hpp"

#include "imgui.h"

MainFrame::MainFrame() { titleBar = std::make_unique<TitleBarFrame>(); }

void MainFrame::update() {}

void MainFrame::render()
{
    const ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove
                                 | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;

    const auto * viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(useWorkArea ? viewport->WorkPos : viewport->Pos);
    ImGui::SetNextWindowSize(useWorkArea ? viewport->WorkSize : viewport->Size);
    ImGui::Begin("Main Window", &open, flags);
    titleBar->render();
    for (const auto pFrame : playerFrames)
    {
        pFrame->render();
        ImGui::SameLine();
    }
    ImGui::End();
}

const std::string MainFrame::getName() { return std::string(); }

void MainFrame::createPlayerFrame(Player * p) { playerFrames.emplace(new PlayerFrame(p)); }
