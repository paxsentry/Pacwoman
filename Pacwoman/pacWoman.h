#ifndef PACWOMAN_H
#define PACWOMAN_H

#include "character.h"

class PacWoman :public Character
{
public:
    PacWoman(sf::Texture& texture);

    void die();

    bool isDead() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates& states) const;

    sf::Sprite m_visual;
    bool m_isDead;
};

#endif  // !PACWOMAN_H