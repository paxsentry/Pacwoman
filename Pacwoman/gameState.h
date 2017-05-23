#ifndef PACWOMAN_GAMESTATE_H
#define PACWOMAN_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "pacWoman.h"
#include "ghost.h"
#include "maze.h"

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
        Lost,
        Count
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
    sf::Text m_text;
    sf::Sprite m_sprite;

    bool m_displayText;
};

class GetReadyState : public GameState
{
public:
    GetReadyState(Game* game, GameState* playingState);

    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
private:
    sf::Text m_text;
    GameState* m_playingState;
};

class PlayingState : public GameState
{
public:
    PlayingState(Game* game);
    ~PlayingState();

    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    void moveCharactersToInitialPosition();
    void updateCameraPosition();
    void loadNextLevel();
    void resetToZero();
    void resetCurrentLevel();
    void resetLiveCount();

private:
    PacWoman* m_pacWoman;
    std::vector<Ghost*> m_ghosts;
    Maze m_maze;

    sf::View m_camera;
    sf::RenderTexture m_scene;

    sf::Text m_scoreText;
    sf::Text m_levelText;
    sf::Text m_remainingDotsText;
    sf::Sprite m_liveSprite[3];

    int m_level;
    int m_liveCount;
    int m_score;
};

class WonState : public GameState
{
public:
    WonState(Game* game, GameState* playingState);

    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);

private:
    sf::Text m_text;

    PlayingState* m_playingState;
};

class LostState : public GameState
{
public:
    LostState(Game* game, GameState* playingState);

    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);

private:
    sf::Text m_text;
    sf::Time m_countDown;
    sf::Text m_countDownText;

    PlayingState* m_playingState;
};

#endif // !PACWOMAN_GAMESTATE_H