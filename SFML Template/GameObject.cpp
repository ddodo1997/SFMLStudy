#include "stdafx.h"

GameObject::GameObject(const std::string& name)
	:name(name), originPreset(Origins::TL), origin(0.f,0.f)
{
}

void GameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = { 0.f,0.f };
}

void GameObject::SetScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
	
}

void GameObject::Init()
{
}

void GameObject::Release()
{
}

void GameObject::Reset()
{
}

void GameObject::Update(float dt)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
}
