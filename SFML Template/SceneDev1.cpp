#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Cloud.h"
#include "BeeGo.h"
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;
	SpriteGo* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	TextGo* text = AddGo(new TextGo("fonts/KOMIKAP_.ttf"));
	text->SetOrigin(Origins::TL);
	text->SetPosition({ 0.f,0.f });
	text->SetString("Dev1");

	for (int i = 0; i < 3; i++)
	{
		Cloud* cloud = AddGo(new Cloud("graphics/cloud.png"));
		cloud->SetBounds({ -100.f, 2000.f }, {0.f, 500.f});
		cloud->SetPosition({ 0.f, 300.f });
	}
	for (int i = 0; i < 3; i++)
	{
		BeeGo* bee = AddGo(new BeeGo("graphics/bee.png"));
		bee->SetXBounds({ -100.f, 2000.f });
		bee->SetYBounds({ 700.f, 800.f });
	}
	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;
	TEXTURE_MANAGER.Load("graphics/background.png");
	TEXTURE_MANAGER.Load("graphics/cloud.png");
	TEXTURE_MANAGER.Load("graphics/bee.png");
	FONT_MANAGER.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;
	TEXTURE_MANAGER.UnLoad("graphics/background.png");
	TEXTURE_MANAGER.UnLoad("graphics/cloud.png");
	TEXTURE_MANAGER.UnLoad("graphics/bee.png");
	FONT_MANAGER.UnLoad("fonts/KOMIKAP_.ttf");
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown())
	{
		SCENE_MANAGER.Instance().ChangeScene(SceneIds::Dev2);
	}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
