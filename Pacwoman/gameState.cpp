#include "gameState.h"
#include "game.h"

GameState::GameState(Game* game)
    :m_game(game)
{
}

NoCoinState::NoCoinState(Game* game)
    : GameState(game)
{
}

Game* GameState::getGame() const
{
    return m_game;
}

void NoCoinState::insertCoin()
{

}

void NoCoinState::pressButton()
{

}

void NoCoinState::moveStick(sf::Vector2i direction)
{

}

void NoCoinState::update(sf::Time delta)
{

}

void NoCoinState::draw(sf::RenderWindow& window)
{

}