#pragma once
class Utils
{
private:
	//난수 생성 엔진
	static std::mt19937 generator;
	static const float PI;

public:
	static void Init();
	// Origin
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& text, Origins preset);
	static int RandomRange(int min, int max);
	static float RandomRange(float min, float max);
	static float RandomValue();  // 0.0f ~ 1.0f
	//원형을 두고, 해당 원 테두리중 한 점의 좌표를 랜덤하게 반환
	static sf::Vector2f RandomOnUnitCircle();
	//원형을 두고, 해당 원 내부의 좌표중 한 점을 랜덤하게 반환
	static sf::Vector2f RandomInUnitCircle();
};

