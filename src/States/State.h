#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum Mode {
	NONE = 0,
	MAINMENU,
	GAME,
	PAUSEMENU,
	GAMEOVER
};

class State {

protected:

	sf::RenderTarget* targetWindow{ nullptr };
	std::vector <sf::Texture> textures;
	bool quit{ false };
	bool pause{ false };
	bool running{ false };
	Mode gameMode = Mode::NONE;

public:
	State(Mode mode, sf::Color color, sf::RenderWindow* window) {
		this->targetWindow = window;
		this->gameMode = mode;
		
	}

};

