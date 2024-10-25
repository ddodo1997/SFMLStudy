#pragma once

/// <summary>
/// GameObject들의 집합
/// </summary>
class Scene
{
protected:
	const SceneIds id;

	std::list<GameObject*> gameObject;


	//빈번히 접근하는것은 포인터로 캐싱해서 잡고있어도 괜찮다.
	//예) Player* player;
public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	template<typename T>
	T* AddGo(T* obj);
	virtual void RemoveGo(GameObject* obj);

	virtual GameObject* FindGo(const std::string& name);
	virtual int FindGoAll(const std::string& name, std::list<GameObject*>& list);
};

template<typename T>
T* Scene::AddGo(T* obj)
{
	if (std::find(gameObject.begin(), gameObject.end(), obj) == gameObject.end())
	{
		gameObject.push_back(obj);
	}

	return obj;
}