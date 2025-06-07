#include "FrameElement.hpp"

#include "core/Core.hpp"

class SkillsElement : public FrameElement
{
public:
    SkillsElement(CreatureId playerId, CreatureType typeIn) : id(playerId), type(typeIn) {}
    void update() override {}
    void draw() override;

private:
    CreatureId id;
    CreatureType type;
};
