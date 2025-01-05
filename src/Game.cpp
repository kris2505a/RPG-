#include "Game.h"


Game::Game() {
	this->initVariables();
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}

void Game::initVariables() {
	this->resolution = sf::VideoMode({ 800, 600 });
	this->fps = 144;
	this->name = "RPG";
}

void Game::initWindow() {
	this->window = new sf::RenderWindow(this->resolution, this->name, sf::Style::Close);
	this->window->setFramerateLimit(this->fps);
}

void Game::render() {

}

void Game::update() {

}