#include "StateManager.h"


StateManager::StateManager(sf::RenderWindow* window) {
	this->targetWindow = window;
}

void StateManager::addState(State* newState, bool removeCurrent) {

	if (removeCurrent && !this->state.empty()) {
		this->state.pop();
	}
	this->state.push(newState);
}


StateManager::~StateManager() {
	while (this->state.empty()) {
		delete this->state.top();
		this->state.pop();
	}
}

State* StateManager::getCurrentState() {
	return this->state.top();
}

bool StateManager::isEmpty() {
	return this->state.empty();
}

void StateManager::popState() {
	this->state.pop();
}

