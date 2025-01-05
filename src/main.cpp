#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Test Window", sf::Style::Close);


	while (window->isOpen()) {
		
		while (std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window->close();
		}
		window->clear();

		window->display();
	}

	delete window;
}