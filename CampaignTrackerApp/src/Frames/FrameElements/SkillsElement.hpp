#include "FrameElement.hpp"

#include "entities/Player.hpp"

class SkillsElement : public FrameElement
{
public:
    SkillsElement(Player * p) : player(p) {}
    void update() override {}
    void draw() override;

private:
    Player * player = nullptr;
};