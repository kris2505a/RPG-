#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Game {

private:
	sf::VideoMode resolution;
	sf::RenderWindow* window{ nullptr };
	float deltaTime;
	int fps;
	std::string name;

public:
	
	Game();
	~Game();
	
	void initVariables();
	void initWindow();
	void render();
	void update();
};

