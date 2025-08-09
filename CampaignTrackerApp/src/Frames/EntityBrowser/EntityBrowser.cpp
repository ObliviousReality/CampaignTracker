#include "EntityBrowser.hpp"

#include "core/Core.hpp"

#include <imgui.h>

EntityBrowser::EntityBrowser(CreatureType t, bool & winOpen) : Frame(), type(t), windowOpen(winOpen)
{
    update();
    eType = CTCore::Get()->creatureTypeToEntityType(t);
}

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

void renderPlayer(EntityId id, EntityType eType)
{
    auto * character = static_cast<Character *>(CTCore::Get()->getEntity(id, eType));
    const auto name = character->getName();
    ImGui::Text(
        "%s Level %i %s %s (%s)",
        name.c_str(),
        character->getLevel(),
        Core::getRaceString(character->getRaceType()).c_str(),
        Core::getClassString(character->getClassType()).c_str(),
        character->getHumanName().c_str());
}

void renderNPC(EntityId id, EntityType eType)
{
    auto * character = static_cast<Character *>(CTCore::Get()->getEntity(id, eType));
    const auto name = character->getName();
    ImGui::Text(
        "%s Level %i %s %s",
        name.c_str(),
        character->getLevel(),
        Core::getRaceString(character->getRaceType()).c_str(),
        Core::getClassString(character->getClassType()).c_str());
}

void renderMonster(EntityId id, EntityType eType)
{
    auto * monster = static_cast<Monster *>(CTCore::Get()->getEntity(id, eType));
    const auto name = monster->getName();
    ImGui::Text("%s, %s", name.c_str(), monster->getMonsterTypeName().c_str());
}

void EntityBrowser::render()
{
    std::string windowName;
    void (*detailFunction)(EntityId, EntityType) = {};

    switch (type)
    {
        case CreatureType::Player:
        {
            windowName = "Player Library";
            detailFunction = renderPlayer;
            break;
        }
        case CreatureType::NPC:
        {
            windowName = "NPC Library";
            detailFunction = renderNPC;
            break;
        }
        case CreatureType::Monster:
        {
            windowName = "Monster Manual";
            detailFunction = renderMonster;
            break;
        }
    }

    if (!detailFunction)
    {
        return;
    }

    if (!ImGui::Begin(windowName.c_str(), &windowOpen))
    {
        ImGui::End();
        return;
    }
    for (const auto id : ids)
    {
        detailFunction(id, eType);
        ImGui::Separator();
    }
    ImGui::End();
}
