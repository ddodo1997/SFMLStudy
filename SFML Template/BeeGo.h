#pragma once
#include "SpriteGo.h"
class BeeGo :
    public SpriteGo
{
protected:
    sf::Vector2f speed;

    sf::Vector2f rangeXSpeed;
    sf::Vector2f rangeYSpeed;
    sf::Vector2f rangeScale;
    sf::Vector2f xBounds;
    sf::Vector2f yBounds;
public:
    BeeGo(std::string texId, std::string name = "");
    ~BeeGo() = default;

    void SetRangeScale(const sf::Vector2f& rangeScale) { this->rangeScale = rangeScale; }
    void SetXBounds(const sf::Vector2f& xBounds) { this->xBounds = xBounds; }
    void SetYBounds(const sf::Vector2f& yBounds) { this->yBounds = yBounds; }
    void Reset()override;
    void Update(float dt)override;

};

