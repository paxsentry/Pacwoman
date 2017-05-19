#include "gameState.h"
#include "game.h"

GameState::GameState(Game* game)
    :m_game(game)
{
}

NoCoinState::NoCoinState(Game* game)
    : GameState(game)
{
    m_sprite.setTexture(game->getLogo());
    m_sprite.setPosition(20, 50);

    m_text.setFont(game->getFont());
    m_text.setString("Insert coin!");
}

GetReadyState::GetReadyState(Game* game)
    : GameState(game)
{
}

PlayingState::PlayingState(Game* game)
    : GameState(game)
{
}

WonState::WonState(Game* game)
    : GameState(game)
{
}

LostState::LostState(Game* game)
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
    window.draw(m_sprite);
    window.draw(m_text);
}

void GetReadyState::insertCoin()
{
}

void GetReadyState::pressButton()
{
}

void GetReadyState::moveStick(sf::Vector2i direction)
{
}

void GetReadyState::update(sf::Time delta)
{
}

void GetReadyState::draw(sf::RenderWindow& window)
{
}

void PlayingState::insertCoin()
{
}

void PlayingState::pressButton()
{
}

void PlayingState::moveStick(sf::Vector2i direction)
{
}

void PlayingState::update(sf::Time delta)
{
}

void PlayingState::draw(sf::RenderWindow& window)
{
}

void WonState::insertCoin()
{
}

void WonState::pressButton()
{
}

void WonState::moveStick(sf::Vector2i direction)
{
}

void WonState::update(sf::Time delta)
{
}

void WonState::draw(sf::RenderWindow& window)
{
}

void LostState::insertCoin()
{
}

void LostState::pressButton()
{
}

void LostState::moveStick(sf::Vector2i direction)
{
}

void LostState::update(sf::Time delta)
{
}

void LostState::draw(sf::RenderWindow& window)
{
}
