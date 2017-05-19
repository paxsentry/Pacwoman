#ifndef PACWOMAN_GAMESTATE_H
#define PACWOMAN_GAMESTATE_H

#include <SFML/Graphics.hpp>

class Game;

class GameState
{
public:
    GameState();

    enum State
    {
        NoCoin,
        GetReady,
        Playing,
        Won,
        Lost
    };

    GameState(Game* game);
    Game* getGame() const;

    virtual void insertCoin() = 0;
    virtual void pressButton() = 0;
    virtual void moveStick(sf::Vector2i direction) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    Game* m_game;
};

class NoCoinState : public GameState
{
public:
    NoCoinState(Game* game);

    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
private:

};

#endif // !PACWOMAN_GAMESTATE_H