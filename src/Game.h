#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "StateManager.h"

class Game {

private:
	sf::VideoMode resolution;
	sf::RenderWindow* window{ nullptr };
	float deltaTime;
	int fps;
	std::string name;
	sf::Clock dtClock;
	StateManager* stateManager;

public:
	
	Game();
	~Game();
	
	void initVariables();
	void initWindow();
	void render();
	void update(float&);
	void updateDeltaTime();
	void gameLoop();
};

