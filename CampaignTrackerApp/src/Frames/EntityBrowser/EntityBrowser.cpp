#include "EntityBrowser.hpp"

#include "core/Core.hpp"

#include <imgui.h>

void EntityBrowser::update()
{
    const auto entityType = CTCore::Get()->creatureTypeToEntityType(type);

    const auto numItems = CTCore::Get()->getObjectCount(entityType);
    if (numItems == ids.size())
    {
        return;
    }
    ids.clear();
    auto it = CTCore::Get()->getIterator(entityType);
    for (const auto item : it)
    {
        if (entityType == EntityType::Character)
        {
            if (CTCore::Get()->getCharacterFromId(item)->getCreatureType() != type)
            {
                continue;
            }
        }
        ids.emplace(item);
    }
}

void EntityBrowser::render()
{
    std::string windowName;

    switch (type)
    {
        case CreatureType::Player:
        {
            windowName = "Player Library";
            break;
        }
        case CreatureType::NPC:
        {
            windowName = "NPC Library";
            break;
        }
        case CreatureType::Monster:
        {
            windowName = "Monster Manual";
            break;
        }
    }

    if (!ImGui::Begin(windowName.c_str(), &windowOpen))
    {
        ImGui::End();
        return;
    }
    for (const auto id : ids)
    {
        ImGui::Text("%i", id);
    }
    ImGui::End();
}