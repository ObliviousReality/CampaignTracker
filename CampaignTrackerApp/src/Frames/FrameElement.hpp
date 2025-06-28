#pragma once

class FrameElement
{
public:
	FrameElement() {}

	virtual void update() = 0;

	virtual void draw() = 0;
};