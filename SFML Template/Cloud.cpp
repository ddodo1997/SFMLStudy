#include "stdafx.h"
#include "Cloud.h"

Cloud::Cloud(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name), rangeSpeed(500.f, 700.f), rangeYSpeed(-700.f,-500.f), rangeScale(1.f, 2.f)
{
}

void Cloud::Reset()
{
	SpriteGo::Reset();
	float scale = Utils::RandomRange(rangeScale.x, rangeScale.y);

	if (Utils::RandomRange(0,1))
	{
		speed.x = Utils::RandomRange(rangeSpeed.x, rangeSpeed.y);
		SetPosition({ xBounds.x, Utils::RandomRange(yBounds.x, yBounds.y) });
		SetScale(-scale, scale);
	}
	else
	{
		speed.x = Utils::RandomRange(rangeYSpeed.x,rangeYSpeed.y);
		SetPosition({ xBounds.y, Utils::RandomRange(yBounds.x, yBounds.y)});
		SetScale(scale, scale);
	}

	SetOrigin(Origins::MC);

}

void Cloud::Update(float dt)
{
	SetPosition(position + speed * dt);
	if (position.x < xBounds.x || position.x > xBounds.y)
	{
		Reset();
	}
}
