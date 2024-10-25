#include "stdafx.h"
#include "BeeGo.h"

BeeGo::BeeGo(std::string texId, std::string name)
	:SpriteGo(texId,name), rangeXSpeed(500.f, 700.f), rangeYSpeed(-700.f, -500.f)
{
}

void BeeGo::Reset()
{
	SpriteGo::Reset();
	if (Utils::RandomRange(0, 1))
	{
		speed.x = Utils::RandomRange(rangeXSpeed.x, rangeXSpeed.y);
		SetPosition({ xBounds.x, Utils::RandomRange(yBounds.x, yBounds.y)});
	}
	else {
		speed.x = Utils::RandomRange(rangeYSpeed.x, rangeYSpeed.y);
		SetPosition({ xBounds.y, Utils::RandomRange(yBounds.x, yBounds.y) });
	}
}

void BeeGo::Update(float dt)
{
	speed.y = sin(position.x/ 200) * 50;
	SetPosition(position + speed * dt);
	if (position.x < xBounds.x || position.x > xBounds.y)
		Reset();
}
