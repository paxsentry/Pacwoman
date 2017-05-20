#include "gameState.h"
#include "game.h"

template <typename T>

void centerOrigin(T& drawable)
{
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width / 2, bound.height / 2);
}

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

    centerOrigin(m_text);
    m_text.setPosition(480, 300);

    m_displayText = true;
}

GetReadyState::GetReadyState(Game* game)
    : GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("Press Start when you're ready...");
    m_text.setCharacterSize(14);

    centerOrigin(m_text);
    m_text.setPosition(480, 480);
}

PlayingState::PlayingState(Game* game)
    : GameState(game),
    //m_pacWoman(game->getTexture()),
    m_pacWoman(nullptr)
    //m_ghost(game->getTexture())
{
    /*m_pacWoman.move(200, 200);
    m_ghost.move(400, 400);*/
    m_maze.loadLevel("level");

    m_pacWoman = new PacWoman(game->getTexture());
    m_pacWoman->setMaze(&m_maze);
    m_pacWoman->setPosition(m_maze.mapCellToPixelPosition(m_maze.getPacWomanPosition()));

    for (auto ghostPosition : m_maze.getGhostPositions()) {
        Ghost* ghost = new Ghost(game->getTexture());
        ghost->setMaze(&m_maze);
        ghost->setPosition(m_maze.mapCellToPixelPosition(ghostPosition));

        m_ghosts.push_back(ghost);
    }
}

PlayingState::~PlayingState()
{
    delete m_pacWoman;
    for (Ghost* ghost : m_ghosts) {
        delete ghost;
    }
}

WonState::WonState(Game* game)
    : GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You won!");
    m_text.setCharacterSize(42);

    centerOrigin(m_text);
    m_text.setPosition(480, 240);
}

LostState::LostState(Game* game)
    : GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You lost!");
    m_text.setCharacterSize(42);

    centerOrigin(m_text);
    m_text.setPosition(480, 240);

    m_countDownText.setFont(game->getFont());
    m_countDownText.setCharacterSize(12);

    centerOrigin(m_countDownText);
    m_countDownText.setPosition(480, 360);
}

Game* GameState::getGame() const
{
    return m_game;
}

void NoCoinState::insertCoin()
{
    getGame()->changeGameState(GameState::GetReady);
}

void NoCoinState::pressButton()
{
}

void NoCoinState::moveStick(sf::Vector2i direction)
{
}

void NoCoinState::update(sf::Time delta)
{
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.5)) {
        m_displayText = !m_displayText;
        timeBuffer -= sf::seconds(1);
    }
}

void NoCoinState::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    if (m_displayText) {
        window.draw(m_text);
    }
}

void GetReadyState::insertCoin()
{
}

void GetReadyState::pressButton()
{
    getGame()->changeGameState(GameState::Playing);
}

void GetReadyState::moveStick(sf::Vector2i direction)
{
    if (direction.x == -1) {
        getGame()->changeGameState(GameState::Lost);
    }

    if (direction.x == 1) {
        getGame()->changeGameState(GameState::Won);
    }
}

void GetReadyState::update(sf::Time delta)
{
}

void GetReadyState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

void PlayingState::insertCoin()
{
    //m_pacWoman.die();
}

void PlayingState::pressButton()
{
    //m_ghost.setWeak(sf::seconds(3));
    //getGame()->changeGameState(GameState::Playing);
}

void PlayingState::moveStick(sf::Vector2i direction)
{
}

void PlayingState::update(sf::Time delta)
{
    m_pacWoman->update(delta);

    for (Ghost* ghost : m_ghosts) {
        ghost->update(delta);
    }
}

void PlayingState::draw(sf::RenderWindow& window)
{
    window.draw(m_maze);

    window.draw(*m_pacWoman);

    for (Ghost* ghost : m_ghosts) {
        window.draw(*ghost);
    }
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
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    if (timeBuffer.asSeconds() >= 5) {
        getGame()->changeGameState(GameState::GetReady);
    }
}

void WonState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
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
    m_countDown += delta;

    if (m_countDown.asSeconds() >= 10) {
        getGame()->changeGameState(GameState::NoCoin);
    }

    m_countDownText.setString("Insert a coin to continue... " +
        std::to_string(10 - static_cast<int>(m_countDown.asSeconds())));
}

void LostState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
    window.draw(m_countDownText);
}
