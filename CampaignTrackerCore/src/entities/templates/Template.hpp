#pragma once

#include <string>

using TemplateId = unsigned int;

enum class TemplateType
{
    Character,
    Monster,
};

class Template
{
public:
    Template(TemplateId _id, TemplateType _type) : id(_id), type(_type) {}

    const TemplateId getId() const { return id; }
    const TemplateType getType() const { return type; }

    void setName(const std::string newName) { name = newName; }
    const std::string & getName() const { return name; }

private:
    TemplateId id;
    TemplateType type;
    std::string name;
};