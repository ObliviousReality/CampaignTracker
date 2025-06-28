#pragma once

#include "entities/Entity.hpp"

#include <array>
#include <map>
#include <memory>
#include <set>

namespace
{
    using EntityMap = std::map<EntityId, std::unique_ptr<Entity>>;
}

struct ObjectMap
{
    EntityMap objectMap;
    EntityId nextFreeId = 0;
};

struct ObjectIterator
{
    std::set<EntityId>::const_iterator begin() { return set.begin(); }
    std::set<EntityId>::const_iterator end() { return set.end(); }
    std::set<EntityId> set = {};
};

class Store
{
public:
    Store();

    Entity * getObject(EntityId id, EntityType type);
    void addObject(EntityId id, EntityType type, Entity * ptr);

    EntityId getNextFreeId(EntityType type);

    ObjectIterator getIterator(EntityType type);

    unsigned int getObjectCount(EntityType type);

private:
    ObjectMap * getMap(EntityType type);

private:
    std::array<std::unique_ptr<ObjectMap>, static_cast<size_t>(EntityType::NUM_ENTITY_TYPES)> objectMaps;
};
