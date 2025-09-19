#pragma once

enum class EntityType
{
    Character,
    Monster,
    CharacterTemplate,
    MonsterTemplate,
    NUM_ENTITY_TYPES,
};

namespace Core
{
    static EntityType entityTypeToTemplateType(EntityType t)
    {
        switch (t)
        {
            case EntityType::Character: return EntityType::CharacterTemplate;
            case EntityType::Monster: return EntityType::MonsterTemplate;
            default: return t;
        }
    }

    static EntityType templateTypeToEntityType(EntityType t)
    {
        switch (t)
        {
            case EntityType::CharacterTemplate: return EntityType::Character;
            case EntityType::MonsterTemplate: return EntityType::Monster;
            default: return t;
        }
    }
}

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
