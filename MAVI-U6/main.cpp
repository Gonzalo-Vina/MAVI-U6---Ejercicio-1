#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 200), "MAVI - Unidad 6");
    window.setFramerateLimit(60);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(100, 0);

    sf::Vector2f tempPosition(-100.0f, 0.0f);

    int round = 1;
    float speed = 100.0f;
    float deltaTime = 1.0f / 60.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
                window.close();
        }

        tempPosition.x += (speed * round) * deltaTime;

        if (tempPosition.x > 900.0f) {
            tempPosition.x = -100;
            if (round < 10) {
                round++;
            }
        }

        shape.setPosition(tempPosition);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}