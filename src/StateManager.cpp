#include "StateManager.h"


StateManager::StateManager(sf::RenderWindow* window) {
	this->targetWindow = window;
}

void StateManager::addState(State* newState, bool removeCurrent = false) {

	if (removeCurrent && !this->state.empty()) {
		this->state.pop();
	}
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

