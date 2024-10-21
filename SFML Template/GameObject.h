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

	//ó�� ������ ��, �ʱ�ȭ ��
	virtual void Init();
	//�����Ҵ��� �ϰ��ִٸ�, �޸� ����
	virtual void Release();
	
	virtual void Reset();

	//Ȱ��ȭ �� ��ü�� �� ������ ������Ʈ�ϰ� ȭ�鿡 �׸�
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};