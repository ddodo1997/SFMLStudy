#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 300), "ddodo's SFML!!");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rShape(sf::Vector2f(400.f, 200.f));
    //shape.setFillColor(sf::Color::Magenta);
    rShape.setFillColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();
        window.draw(rShape);
        window.draw(shape);
        window.display();
    }

    return 0;
}