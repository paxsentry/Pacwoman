#include "game.h"

Game::Game() :m_window(sf::VideoMode(1280, 960), "Pac Woman")
{
}

void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { m_window.close(); }

            if (event.key.code == sf::Keyboard::I) { m_currentState->insertCoin(); }

            if (event.key.code == sf::Keyboard::S) { m_currentState->pressButton(); }

            if (event.key.code == sf::Keyboard::Left) { m_currentState->moveStick(sf::Vector2i(-1, 0)); }
            if (event.key.code == sf::Keyboard::Right) { m_currentState->moveStick(sf::Vector2i(1, 0)); }
            if (event.key.code == sf::Keyboard::Up) { m_currentState->moveStick(sf::Vector2i(0, -1)); }
            if (event.key.code == sf::Keyboard::Down) { m_currentState->moveStick(sf::Vector2i(0, 1)); }

            m_currentState->update(sf::seconds(1));
            m_window.clear();
            m_currentState->draw(m_window);
            m_window.display();
        }
    }
}

void Game::changeGameState(GameState::State gameState)
{

}

GameState::GameState()
{
}