#ifndef PACWOMAN_GAME_H
#define PACWOMAN_GAME_H

#include <SFML/Graphics.hpp>
#include "gameState.h"
#include <array>

class Game
{
public:
    Game();
    ~Game();

    void run();
    void changeGameState(GameState::State gameState);

    sf::Font& getFont();
    sf::Texture& getLogo();
    sf::Texture& getTexture();

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::Count>m_gameStates;

    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
};

#endif // !PACWOMAN_GAME_H