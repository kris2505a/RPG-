#include "Game.h"


Game::Game() {
	this->initVariables();
	this->initWindow();
}



void Game::initVariables() {
	this->resolution = sf::VideoMode({ 1024, 768 });
	this->fps = 144;
	this->name = "RPG";
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


	this->window->display();
}

void Game::update(float& deltaTime) {

}

void Game::updateDeltaTime() {
	this->deltaTime = this->dtClock.restart().asSeconds();
}


Game::~Game() {
	delete this->window;
}