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

            if (event.key.code == sf::Keyboard::I) { insertCoin(); }

            if (event.key.code == sf::Keyboard::S) { pressButton(); }

            if (event.key.code == sf::Keyboard::Left) { moveStick(sf::Vector2i(-1, 0)); }
            if (event.key.code == sf::Keyboard::Right) { moveStick(sf::Vector2i(1, 0)); }
            if (event.key.code == sf::Keyboard::Up) { moveStick(sf::Vector2i(0, -1)); }
            if (event.key.code == sf::Keyboard::Down) { moveStick(sf::Vector2i(0, 1)); }

            m_window.clear();

            m_window.display();
        }
    }
}

void Game::insertCoin()
{
}

void Game::pressButton()
{
}

void Game::moveStick(sf::Vector2i direction)
{
}
