#pragma once
#define TEXTURE_MANAGER (ResourceMgr<sf::Texture>::Instance())
#define FONT_MANAGER (ResourceMgr<sf::Font>::Instance())
#define FRAMEWORK (Framework::Instance())
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include "Singleton.h"
#include "Framework.h"
#include "ResourceMgr.h"
#include "InputMgr.h"
#include "GameObject.h"