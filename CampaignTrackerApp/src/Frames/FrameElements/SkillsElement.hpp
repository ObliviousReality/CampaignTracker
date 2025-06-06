#include "FrameElement.hpp"

#include "core/Core.hpp"

class SkillsElement : public FrameElement
{
public:
    SkillsElement(CreatureId playerId) : id(playerId) {}
    void update() override {}
    void draw() override;

private:
    CreatureId id;
};