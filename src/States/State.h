#pragma once
#include <SFML/Graphics.hpp>

class State {

private:

	sf::RenderTarget* targetWindow{ nullptr };
	bool tick{ false };

public:

	State() { this->tick = true; }
	virtual ~State(){}
	void setTick(bool newTick) { this->tick = newTick; }
	virtual void render() = 0;
	virtual void update(float&) = 0;
};

