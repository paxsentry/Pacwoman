#ifndef PACWOMAN_GHOST_H
#define PACWOMAN_GHOST_H

#include "character.h"
#include "pacWoman.h"

class Ghost :public Character
{
public:
    Ghost(sf::Texture& texture);

    enum State {
        Strong,
        Weak
    };

    void setWeak(sf::Time duration);
    bool isWeak() const;


private:
    void draw(sf::RenderTarget& target, sf::RenderStates& states) const;

    sf::Sprite m_visual;
    bool m_isWeak;
    sf::Time m_weaknessDuration;
};

#endif  // !PACWOMAN_GHOST_H