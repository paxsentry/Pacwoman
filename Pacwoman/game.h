#ifndef PACWOMAN_GAME_H
#define PACWOMAN_GAME_H

#include <SFML/Graphics.hpp>
#include "gameState.h"

class Game
{
public:
    Game();
    
    void run();

    void changeGameState(GameState::State gameState);

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
};

#endif // !PACWOMAN_GAME_H