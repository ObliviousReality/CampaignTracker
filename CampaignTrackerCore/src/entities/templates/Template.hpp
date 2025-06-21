#pragma once

#include "entities/Entity.hpp"

#include <string>

class Template : public Entity
{
public:
    Template(EntityId id, EntityType type) : Entity(id, type) {}

    void setName(const std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

private:
    std::string name;
};
