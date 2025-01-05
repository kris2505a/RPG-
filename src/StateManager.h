#pragma once
#include "States/State.h"
#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>

class StateManager {
	
private:
	sf::RenderWindow* targetWindow;
	std::stack <State*> state;

public:
	
	void addState(State*, bool = false);
	void popState();
	bool isEmpty();
	State* getCurrentState();


	StateManager(sf::RenderWindow*);
	~StateManager();

};

