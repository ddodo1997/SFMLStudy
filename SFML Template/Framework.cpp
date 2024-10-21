#include "stdafx.h"
#include "SpriteGo.h"
void Framework::Init(int width, int height, const std::string& title)
{


	window.create(sf::VideoMode(width, height), title);
}

void Framework::Do()
{
	TEXTURE_MANAGER.Load("graphics/background.png");

	SpriteGo go("graphics/background.png");
	go.Init();
	go.Reset();
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		realDeltaTime = deltaTime = dt.asSeconds();
		deltaTime *= timeScale;
		realTime += realDeltaTime;
		time += deltaTime;

		InputMgr::Clear();


		//�̺�Ʈ
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}
		//������Ʈ
		go.Update(deltaTime);


		//��ο�
		window.clear();
		go.Draw(window);
		window.display();
	}
	go.Release();
}

void Framework::Release()
{
}
