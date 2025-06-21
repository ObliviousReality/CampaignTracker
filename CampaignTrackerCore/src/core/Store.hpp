#pragma once

#include "entities/Entity.hpp"

#include <array>
#include <map>
#include <memory>

struct ObjectMap
{
    std::map<EntityId, std::unique_ptr<Entity>> objectMap;
    EntityId nextFreeId = 0;
};

class Store
{
public:
    Store();

    Entity * getObject(EntityId id, EntityType type);
    void addObject(EntityId id, EntityType type, Entity * ptr);

    EntityId getNextFreeId(EntityType type);

private:
    ObjectMap * getMap(EntityType type);

private:
    std::array<std::unique_ptr<ObjectMap>, static_cast<size_t>(EntityType::NUM_ENTITY_TYPES)> objectMaps;
};
