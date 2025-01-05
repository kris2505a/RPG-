#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class State {

private:

	sf::RenderTarget* targetWindow{ nullptr };
	std::vector <sf::Texture> textures;
	bool quitStatus{ false };
	bool runningStatus{ false };



public:

	State() {
		this->runningStatus = true;
	}
	virtual ~State() {}
	virtual void render() = 0;
	virtual void update(float&) = 0;
	bool shoudQuit() {
		return this->quitStatus;
	}
	bool isRunning() {
		return this->runningStatus;
	}
};

