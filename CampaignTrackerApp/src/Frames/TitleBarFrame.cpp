#include "TitleBarFrame.hpp"

#include "Application/ApplicationManager.hpp"

#include "core/Core.hpp"

void TitleBarFrame::update() {}

void TitleBarFrame::render()
{
    if (ImGui::BeginMenuBar())
    {
        titleBarSize = ImGui::GetWindowSize();
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Save")) {}
            if (ImGui::MenuItem("Load")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Import")) {}
            if (ImGui::MenuItem("Export")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Close", "Alt+F4"))
            {
                ApplicationManager::Get()->setAppRunning(false);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Edit Mode", nullptr, &editMode)) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Clear Tracker")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Full Heal All")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Insert"))
        {
            if (ImGui::BeginMenu("Player"))
            {
                for (int i = 0; i < 4; ++i)
                {
                    const auto name = CTCore::Get()->getCreatureFromId<Player>(i, CreatureType::Player)->getName();
                    if (ImGui::MenuItem(name.c_str())) {}
                }
                if (ImGui::MenuItem("More...")) {}
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("NPC")) {}
            if (ImGui::MenuItem("Monster")) {}
            if (ImGui::MenuItem("Encounter")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View"))
        {
            if (ImGui::MenuItem("Player Library")) {}
            if (ImGui::MenuItem("NPC Library")) {}
            if (ImGui::MenuItem("Monster Manual")) {}
            if (ImGui::MenuItem("Saved Encounters")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Dice Well", nullptr, &diceWellOpen)) {}
            if (ImGui::MenuItem("Log", nullptr, &logOpen)) {}
            if (ImGui::MenuItem("Show Environment", nullptr, &showEnvironment)) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Create"))
        {
            if (ImGui::MenuItem("Player")) {}
            if (ImGui::MenuItem("NPC")) {}
            if (ImGui::MenuItem("Monster")) {}
            ImGui::Separator();
            if (ImGui::BeginMenu("Template"))
            {
                if (ImGui::MenuItem("NPC")) {}
                if (ImGui::MenuItem("Monster")) {}
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Encounter")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("Open Help Page")) {}
            if (ImGui::MenuItem("Raise Issue")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("About"))
        {
            if (ImGui::MenuItem("About App")) {}
            if (ImGui::MenuItem("Open Source")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

const std::string TitleBarFrame::getName() { return std::string(); }
