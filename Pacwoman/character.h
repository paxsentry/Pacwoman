#ifndef PACWOMAN_CHARACTER_H
#define PACWOMAN_CHARACTER_H

#include <SFML\Graphics.hpp>
#include "maze.h"

class Character : public sf::Drawable, public sf::Transformable
{
public:
    Character();

    virtual void update(sf::Time delta);
    void setDirection(sf::Vector2i direction);
    sf::Vector2i getDirection() const;
    void setMaze(Maze* maze);

    void setSpeed(float speed);
    float getSpeed() const;

private:
    float m_speed;
    sf::Vector2i m_currentDirection;
    sf::Vector2i m_nextDirection;
    Maze* m_maze;
};

#endif  // !PACWOMAN_CHARACTER_H