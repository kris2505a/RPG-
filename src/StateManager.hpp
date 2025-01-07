#pragma once
#include "States/States.hpp"
#include "States/State.hpp"

#include <stack>
#include <memory>

class StateManager{


private:
    std::stack <State*> states;
    sf::RenderWindow* targetWindow;
    float pauseMenuLatency;
    sf::Clock latencyClock;

public:
    StateManager(sf::RenderWindow* window){
        this->targetWindow = window;
    }

    State* getCurrentState(){
        if(this->states.empty())
            return nullptr;
        return this->states.top();
    }

    void addState(State* state){
        this->states.push(state);
    }

    void popState(){
        if(!this->states.empty())
            this->states.pop();
    }

    void handleInput(){

        this->pauseMenuLatency = latencyClock.getElapsedTime().asSeconds();
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->pauseMenuLatency > 0.5f){
            switch (this->states.top()->getMode()) {
            
            case Mode::GAME:
                states.top()->onPause();
                states.push(new PauseMenu(this->targetWindow));
                latencyClock.restart().asSeconds();
                break;
            
            case Mode::PAUSEMENU:
                delete states.top();
                states.pop();
                states.top()->onResume();
                latencyClock.restart().asSeconds();
                break;
            }
        }
    }

};