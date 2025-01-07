#pragma once
#include "SFML/Graphics.hpp"

enum Mode {
    NONE = 0,
    GAME,
    PAUSEMENU,
    MAINMENU,
    GAMEOVER
};

class State{

protected:
    sf::RenderTarget* targetWindow;
    Mode stateMode;
    bool handleInputCondition {true};

public:
    State() = default;
    virtual ~State() = default;

    virtual void render() = 0;
    virtual void update(float&) = 0;
    virtual void handleInput() = 0;

    virtual void onPause() {}
    virtual void onResume() {}

    Mode getMode(){
        return this->stateMode;
    }

};


