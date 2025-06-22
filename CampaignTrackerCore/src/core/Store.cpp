#include "Store.hpp"

#include <ranges>

Store::Store()
{
    for (int i = 0; i < static_cast<int>(EntityType::NUM_ENTITY_TYPES); ++i)
    {
        objectMaps[i] = std::make_unique<ObjectMap>();
    }
}

Entity * Store::getObject(EntityId id, EntityType type)
{
    const auto & map = getMap(type)->objectMap;

    auto f = map.find(id);
    if (f != map.cend())
    {
        return f->second.get();
    }

    return nullptr;
}

void Store::addObject(EntityId id, EntityType type, Entity * ptr)
{
    if (getObject(id, type))
    {
        // error! TODO: Add assert
        printf("Error: Attempting to create an object that already exists!\n");
    }
    auto map = getMap(type);
    map->objectMap.emplace(id, std::unique_ptr<Entity>(ptr));
}

EntityId Store::getNextFreeId(EntityType type) { return getMap(type)->nextFreeId++; }

ObjectIterator Store::getIterator(EntityType type)
{
    ObjectIterator it;
    auto ks = std::views::keys(getMap(type)->objectMap);
    it.set = { ks.begin(), ks.end() };
    return it;
}

ObjectMap * Store::getMap(EntityType type) { return objectMaps[static_cast<int>(type)].get(); }
