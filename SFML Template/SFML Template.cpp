#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputMgr.h"
#include "ResourceMgr.h"

#define TEXTURE_MANAGER ResourceMgr<sf::Texture>::Instance()
#define FONT_MANAGER ResourceMgr<sf::Font>::Instance()


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 300), "ddodo's SFML!!");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rShape(sf::Vector2f(400.f, 200.f));
    rShape.setFillColor(sf::Color::Red);

    TEXTURE_MANAGER.Load("graphics/player.png");

    sf::Sprite spr(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));

    while (window.isOpen())
    {
        InputMgr::Clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }

        //업데이트

        sf::Vector2i mousePoint(InputMgr::GetMousePoint());
        if (InputMgr::GetKeyDown())
            std::cout << "Key Down..." << std::endl;
        if (InputMgr::GetKey())
            std::cout << "Key Pressed..." << std::endl;
        if (InputMgr::GetKeyUp())
            std::cout << "Key Up..." << std::endl;

        if (InputMgr::GetMouseDown())
            std::cout << "Mouse Down..." << std::endl;
        if (InputMgr::GetMouse())
            std::cout << "Mouse Pressed...(x : " << mousePoint.x << " y : " << mousePoint.y << ")" << std::endl;
        if (InputMgr::GetMouseUp())
            std::cout << "Mouse Up..." << std::endl;

        window.clear();
        window.draw(rShape);
        window.draw(shape);
        window.draw(spr);
        window.display();
    }
    return 0;
}