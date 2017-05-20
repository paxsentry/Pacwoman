#ifndef PACWOMAN_H
#define PACWOMAN_H

#include "character.h"
#include "animator.h"

class PacWoman :public Character
{
public:
    PacWoman(sf::Texture& texture);

    void die();

    bool isDying() const;
    bool isDead() const;

    void update(sf::Time delta);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite m_visual;
    bool m_isDying;
    bool m_isDead;

    Animator m_runAnimator;
    Animator m_dieAnimator;
};

#endif  // !PACWOMAN_H