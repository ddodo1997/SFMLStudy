#pragma once
#include "stdafx.h"
class GameObject
{
protected:
	bool active = true;
	sf::Vector2f position;

public:
	GameObject() = default;
	~GameObject() = default;

	bool IsActive() const { return active; }
	void SetActive(bool active) { this->active = active; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& position) { this->position = position; }

	//처음 생성할 때, 초기화 함
	virtual void Init();
	//동적할당을 하고있다면, 메모리 정리
	virtual void Release();
	
	virtual void Reset();

	//활성화 된 객체를 매 프레임 업데이트하고 화면에 그림
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};