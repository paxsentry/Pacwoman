#ifndef PACWOMAN_MAZE_H
#define PACWOMAN_MAZE_H

#include <array>
#include <SFML\Graphics.hpp>

class Maze : public sf::Drawable
{
public:
    Maze();

    void loadLevel(std::string name);

    sf::Vector2i getPacWomanPosition() const;
    std::vector<sf::Vector2i> getGhostPositions() const;

    inline std::size_t positionToIndex(sf::Vector2i position) const;
    inline sf::Vector2i indexToPosition(std::size_t index) const;

    sf::Vector2i mapPixelToCellPosition(sf::Vector2f pixel) const;
    sf::Vector2f mapCellToPixelPosition(sf::Vector2i cell) const;

private:
    enum CellData
    {
        Empty,
        Wall,
        Dot,
        SuperDot,
        Bonus
    };

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Vector2i m_mazeSize;
    std::vector<CellData> m_mazeData;
    sf::Vector2i m_pacWomanPosition;
    std::vector<sf::Vector2i> m_ghostPositions;

    sf::RenderTexture m_renderTexture;
};

#endif // !PACWOMAN_MAZE_H