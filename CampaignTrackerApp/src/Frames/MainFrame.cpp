#include "MainFrame.hpp"

#include "Frames/CharacterFrame.hpp"
#include "Frames/MonsterFrame.hpp"

#include "imgui.h"

MainFrame::MainFrame()
{
    titleBar = std::make_unique<TitleBarFrame>();
    tabBar = std::make_unique<TabBarFrame>();
}

void MainFrame::update() {}

void MainFrame::render()
{
    const ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove
                                 | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;

    const auto * viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(useWorkArea ? viewport->WorkPos : viewport->Pos);
    ImGui::SetNextWindowSize(useWorkArea ? viewport->WorkSize : viewport->Size);
    if (ImGui::Begin("Main Window", &open, flags))
    {
        titleBar->render();
        tabBar->render();
        const auto numFrames = characterFrames.size() + monsterFrames.size();
        const float totalWidth = (233.0f) * numFrames;
        const auto tableFlags = ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingStretchSame
                              | ImGuiTableFlags_BordersInnerV
                              | ImGuiTableFlags_Reorderable /*| ImGuiTableFlags_Resizable*/;
        auto & style = ImGui::GetStyle();
        auto outerSize = ImGui::GetWindowSize();
        outerSize[0] -= 2 * style.WindowPadding[0];
        outerSize[1] -= titleBar->getSize()[1];
        if (ImGui::BeginTable("###Players", static_cast<int>(numFrames), tableFlags, outerSize, totalWidth))
        {
            //for (int i = 0; i < characterFrames.size(); ++i)
            //{
            //    ImGui::TableSetupColumn(std::to_string(i + 1).c_str());
            //}
            //ImGui::TableHeadersRow();
            for (const auto pFrame : characterFrames)
            {
                ImGui::TableNextColumn();
                pFrame->render();
                ImGui::SameLine();
            }
            for (const auto pFrame : monsterFrames)
            {
                ImGui::TableNextColumn();
                pFrame->render();
                ImGui::SameLine();
            }
            ImGui::EndTable();
        }
        ImGui::End();
    }
}

const std::string MainFrame::getName() { return std::string(); }

void MainFrame::createCharacterFrame(EntityId playerId) { characterFrames.emplace_back(new CharacterFrame(playerId)); }

void MainFrame::createMonsterFrame(EntityId monsterId) { monsterFrames.emplace_back(new MonsterFrame(monsterId)); }
