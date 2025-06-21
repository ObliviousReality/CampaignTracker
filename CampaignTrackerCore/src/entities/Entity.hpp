#pragma once

enum class EntityType
{
    Character,
    Monster,
    CharacterTemplate,
    MonsterTemplate,
    NUM_ENTITY_TYPES,
};

using EntityId = unsigned int;

class Entity
{
public:
    Entity(EntityId _id, EntityType _type) : id(_id), type(_type) {}

    EntityId getId() const { return id; }
    EntityType getType() const { return type; }

private:
    EntityId id;
    EntityType type;
};
