#include "stdafx.h"
#include "Utils.h"
#include <cmath>

std::mt19937 Utils::generator;
const float Utils::PI = acosf(-1.f);

void Utils::Init()
{
    //시드 생성
    std::random_device rd;
    //시드 넣어주기
    generator.seed(rd());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();

    sf::Vector2f newOrigin(rect.width, rect.height);

    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);

    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& text, Origins preset)
{
    sf::FloatRect rect = text.getLocalBounds();

    sf::Vector2f newOrigin(rect.width, rect.height);

    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    text.setOrigin(newOrigin);

    return newOrigin;
}

int Utils::RandomRange(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);

    return dist(generator);
}

float Utils::RandomRange(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);

    return dist(generator);
}

float Utils::RandomValue()
{
    return RandomRange(0.f, 1.f);
}

sf::Vector2f Utils::RandomOnUnitCircle()
{
    //0 ~ 360 사이의 각도를 생성
    float angle = RandomRange(0.f, 2.f * PI) ;

    return sf::Vector2f(std::cosf(angle), std::sinf(angle));
}

sf::Vector2f Utils::RandomInUnitCircle()
{
    return RandomOnUnitCircle() * RandomValue();
}
