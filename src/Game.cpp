#include "Game.h"


Game::Game() {
	this->initVariables();
	this->initWindow();
}



void Game::initVariables() {
	this->resolution = sf::VideoMode({ 1024, 768 });
	this->fps = 144;
	this->name = "RPG";
	this->stateManager = new StateManager(this->window);
}

void Game::initWindow() {
	this->window = new sf::RenderWindow(this->resolution, this->name, sf::Style::Close);
	this->window->setFramerateLimit(this->fps);
}

void Game::gameLoop() {
	
	while (this->window->isOpen()) {
		while (std::optional event = window->pollEvent()) {
			if (event->is <sf::Event::Closed>())
				window->close();
		}
		this->updateDeltaTime();
		this->update(this->deltaTime);
		this->render();
	}
}

void Game::render() {
	this->window->clear(sf::Color::Black);
	
	if (!this->stateManager->isEmpty()) {
		this->stateManager->getCurrentState()->render();
	}

	this->window->display();
}

void Game::update(float& deltaTime) {
	if (!this->stateManager->isEmpty())
		this->stateManager->getCurrentState()->handleInput(this->deltaTime);
		this->stateManager->getCurrentState()->update(this->deltaTime);
}

void Game::updateDeltaTime() {
	this->deltaTime = this->dtClock.restart().asSeconds();
}


Game::~Game() {
	delete this->window;
}