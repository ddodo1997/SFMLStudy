#pragma once
#include "SpriteGo.h"
class Cloud :
    public SpriteGo
{
protected:
    //현재 속도
    sf::Vector2f speed;

    //x = 최소값 , y = 최대값
    sf::Vector2f rangeSpeed;
    sf::Vector2f rangeYSpeed;
    sf::Vector2f rangeScale;
    sf::Vector2f xBounds;
    sf::Vector2f yBounds;
public:
    Cloud(const std::string& texId, const std::string& name = "");
    ~Cloud() = default;

    void SetRangeSpeed(const sf::Vector2f& speed) { this->rangeSpeed = speed; }
    void SetXBounds(const sf::Vector2f& xBounds) { this->xBounds = xBounds; }
    void SetYBounds(const sf::Vector2f& yBounds) { this->yBounds = yBounds; }
    void SetRangeScale(const sf::Vector2f& rangeScale) { this->rangeScale = rangeScale; }
    void Reset()override;
    void Update(float dt)override;
};