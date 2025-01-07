#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include "States/States.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    float deltaTime {0.0f};

    StateManager stateManager(&window);
    stateManager.addState(new MainGame(&window));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        stateManager.getCurrentState()->update(deltaTime);
        stateManager.getCurrentState()->render();
        stateManager.getCurrentState()->handleInput();
        stateManager.handleInput();
         

        window.display();
    }

    return 0;
}