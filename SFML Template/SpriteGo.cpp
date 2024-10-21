#include "stdafx.h"
#include "SpriteGo.h"


SpriteGo::SpriteGo(const std::string& textureId)
	:textureId(textureId)
{
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MANAGER.Get(textureId));
}

void SpriteGo::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}
