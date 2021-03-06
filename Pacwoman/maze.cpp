#include "maze.h"
#include "dot.h"
#include <iostream>
#include <cassert>

Maze::Maze(sf::Texture& texture)
    :m_mazeSize(0, 0),
    m_texture(texture)
{}

void Maze::loadLevel(std::string name)
{
    m_mazeSize = sf::Vector2i(0, 0);
    m_mazeData.clear();

    m_pacWomanPosition = sf::Vector2i(0, 0);
    m_ghostPositions.clear();

    sf::Image levelData;

    if (!levelData.loadFromFile("assets/levels/" + name + ".png"))
    {
        throw std::runtime_error("Failed to load level (" + name + ")");
    }
    m_mazeSize = sf::Vector2i(levelData.getSize());

    if (m_mazeSize.x < 15 || m_mazeSize.y < 15)
    {
        throw std::runtime_error("The loaded level is too small (min 15 cells)");
    }

    for (unsigned int y = 0; y < m_mazeSize.y; y++)
    {
        for (unsigned int x = 0; x < m_mazeSize.x; x++)
        {
            sf::Color cellData = levelData.getPixel(x, y);

            if (cellData == sf::Color::Black) { m_mazeData.push_back(Wall); }
            else if (cellData == sf::Color::White) { m_mazeData.push_back(Dot); }
            else if (cellData == sf::Color::Green) { m_mazeData.push_back(SuperDot); }
            else if (cellData == sf::Color::Blue)
            {
                m_pacWomanPosition = sf::Vector2i(x, y);
                m_mazeData.push_back(Empty);
            } // PacWoman position
            else if (cellData == sf::Color::Red)
            {
                m_ghostPositions.push_back(sf::Vector2i(x, y));
                m_mazeData.push_back(Empty);
            } // Ghost position
            else { m_mazeData.push_back(Empty); }
        }
    }

    m_renderTexture.create(32 * m_mazeSize.x, 32 * m_mazeSize.y);
    m_renderTexture.clear(sf::Color::Black);

    sf::RectangleShape wall;
    wall.setSize(sf::Vector2f(32, 32));
    wall.setFillColor(sf::Color::Blue);

    sf::Sprite border(m_texture);
    border.setTextureRect(sf::IntRect(16, 0, 16, 32));
    border.setOrigin(0, 16);

    sf::Sprite innerBorder(m_texture);
    innerBorder.setTextureRect(sf::IntRect(0, 0, 16, 16));
    innerBorder.setOrigin(0, 16);

    sf::Sprite outerBorder(m_texture);
    outerBorder.setTextureRect(sf::IntRect(0, 16, 16, 16));
    outerBorder.setOrigin(0, 16);

    m_renderTexture.display();

    for (unsigned int i = 0; i < m_mazeData.size(); i++)
    {
        sf::Vector2i position = indexToPosition(i);

        if (isWall(position))
        {
            wall.setPosition(32 * position.x, 32 * position.y);
            m_renderTexture.draw(wall);

            border.setPosition(mapCellToPixelPosition(position));
            innerBorder.setPosition(mapCellToPixelPosition(position));
            outerBorder.setPosition(mapCellToPixelPosition(position));

            if (!isWall(position + sf::Vector2i(1, 0)))
            {
                border.setRotation(0);
                m_renderTexture.draw(border);
            }

            if (!isWall(position + sf::Vector2i(0, 1)))
            {
                border.setRotation(90);
                m_renderTexture.draw(border);
            }

            if (!isWall(position + sf::Vector2i(-1, 0)))
            {
                border.setRotation(180);
                m_renderTexture.draw(border);
            }

            if (!isWall(position + sf::Vector2i(0, -1)))
            {
                border.setRotation(270);
                m_renderTexture.draw(border);
            }

            if (isWall(position + sf::Vector2i(1, 0)) && isWall(position + sf::Vector2i(0, -1)))
            {
                innerBorder.setRotation(0);
                m_renderTexture.draw(innerBorder);
            }

            if (isWall(position + sf::Vector2i(0, 1)) && isWall(position + sf::Vector2i(1, 0)))
            {
                innerBorder.setRotation(90);
                m_renderTexture.draw(innerBorder);
            }

            if (isWall(position + sf::Vector2i(-1, 0)) && isWall(position + sf::Vector2i(0, 1)))
            {
                innerBorder.setRotation(180);
                m_renderTexture.draw(innerBorder);
            }

            if (isWall(position + sf::Vector2i(0, -1)) && isWall(position + sf::Vector2i(-1, 0)))
            {
                innerBorder.setRotation(270);
                m_renderTexture.draw(innerBorder);
            }

            if (!isWall(position + sf::Vector2i(1, 0)) && !isWall(position + sf::Vector2i(0, -1)))
            {
                outerBorder.setRotation(0);
                m_renderTexture.draw(outerBorder);
            }

            if (!isWall(position + sf::Vector2i(0, 1)) && !isWall(position + sf::Vector2i(1, 0)))
            {
                outerBorder.setRotation(90);
                m_renderTexture.draw(outerBorder);
            }

            if (!isWall(position + sf::Vector2i(-1, 0)) && !isWall(position + sf::Vector2i(0, 1)))
            {
                outerBorder.setRotation(180);
                m_renderTexture.draw(outerBorder);
            }

            if (!isWall(position + sf::Vector2i(0, -1)) && !isWall(position + sf::Vector2i(-1, 0)))
            {
                outerBorder.setRotation(270);
                m_renderTexture.draw(outerBorder);
            }
        }
    }
}

sf::Vector2i Maze::getPacWomanPosition() const
{
    return m_pacWomanPosition;
}

std::vector<sf::Vector2i> Maze::getGhostPositions() const
{
    return m_ghostPositions;
}

std::size_t Maze::positionToIndex(sf::Vector2i position) const
{
    return position.y * m_mazeSize.x + position.x;
}

sf::Vector2i Maze::indexToPosition(std::size_t index) const
{
    sf::Vector2i position;

    position.x = index % m_mazeSize.x;
    position.y = index / m_mazeSize.x;

    return position;
}

sf::Vector2i Maze::mapPixelToCellPosition(sf::Vector2f pixel) const
{
    sf::Vector2i cell;

    cell.x = std::floor(pixel.x / 32.f);
    cell.y = std::floor(pixel.y / 32.f);

    return cell;
}

sf::Vector2f Maze::mapCellToPixelPosition(sf::Vector2i cell) const
{
    sf::Vector2f pixel;

    pixel.x = cell.x * 32 + 16;
    pixel.y = cell.y * 32 + 16;

    return pixel;
}

bool Maze::isWall(sf::Vector2i position) const
{
    if (position.x < 0 ||
        position.y < 0 ||
        position.x >= m_mazeSize.x ||
        position.y >= m_mazeSize.y)
    {
        return false;
    }

    return m_mazeData[positionToIndex(position)] == Wall;
}

bool Maze::isDot(sf::Vector2i position)const
{
    return m_mazeData[positionToIndex(position)] == Dot;
}

bool Maze::isSuperDot(sf::Vector2i position) const
{
    return m_mazeData[positionToIndex(position)] == SuperDot;
}

bool Maze::isBonus(sf::Vector2i position) const
{
    return m_mazeData[positionToIndex(position)] == Bonus;
}

void Maze::pickObject(sf::Vector2i position)
{
    assert(!isWall(position));
    m_mazeData[positionToIndex(position)] = Empty;
}

sf::Vector2i Maze::getSize() const
{
    return m_mazeSize;
}

void Maze::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(m_renderTexture.getTexture()), states);

    static sf::CircleShape dot = getDot();
    static sf::CircleShape superDot = getSuperDot();

    for (unsigned int i = 0; i < m_mazeData.size(); i++)
    {
        sf::Vector2i position = indexToPosition(i);

        if (m_mazeData[i] == Dot)
        {
            dot.setPosition(32 * position.x + 16, 32 * position.y + 16);
            target.draw(dot, states);
        }
        else if (m_mazeData[i] == SuperDot)
        {
            superDot.setPosition(32 * position.x + 16, 32 * position.y + 16);
            target.draw(superDot, states);
        }
    }
}

int Maze::getRemainingDots() const
{
    int remainingDots = 0;

    for (unsigned int i = 0; i < m_mazeData.size(); i++)
    {
        if (m_mazeData[i] == Dot || m_mazeData[i] == SuperDot)
        {
            remainingDots++;
        }
    }

    return remainingDots;
}