#pragma once
#include "State.hpp"


class MainGame : public State {

private:
    sf::CircleShape circle;

public:
    MainGame(sf::RenderWindow* window){
        this->targetWindow = window;
        this->stateMode = Mode::GAME;
        this->circle.setFillColor(sf::Color::White);
        this->circle.setRadius(100);
        this->circle.setPosition({250, 250});
    }

    virtual void render(){
        this->targetWindow->draw(this->circle);
    }

    virtual void update(float& delatTime){
        
    }

    virtual void handleInput(){
        if (!this->handleInputCondition)
            return;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            float speed = 2.f;
            sf::Vector2f deltaLoc = circle.getPosition();
            deltaLoc.x += speed;
            this->circle.setPosition(deltaLoc);
        }
    }

    virtual void Pause(){
        this->handleInputCondition = false;
    }

    virtual void Resume(){
        this->handleInputCondition = true;
    }
};


class PauseMenu : public State {

private:
    sf::CircleShape circle;

public:

    PauseMenu(sf::RenderWindow* window){
        this->targetWindow = window;
        this->stateMode = Mode::PAUSEMENU;
        this->circle.setFillColor(sf::Color::Cyan);
        this->circle.setRadius(100);
        this->circle.setPosition({400, 400});
    }

        virtual void render(){
        this->targetWindow->draw(this->circle);
    }

    virtual void update(float& delatTime){
        
    }

    virtual void handleInput(){
        if (!this->handleInputCondition)
            return;
    }


};