#pragma once
#include "stdafx.h"
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo() = default;
	~SpriteGo() = default;

	void SetPosition(const sf::Vector2f& position) override;

	SpriteGo(const std::string& textureId);
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;
};


