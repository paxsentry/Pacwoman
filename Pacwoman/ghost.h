#ifndef PACWOMAN_GHOST_H
#define PACWOMAN_GHOST_H

#include "character.h"
#include "animator.h"
#include "pacWoman.h"

class Ghost :public Character
{
public:
    Ghost(sf::Texture& texture, PacWoman* pacWoman);

    enum State {
        Strong,
        Weak
    };

    void setWeak(sf::Time duration);
    bool isWeak() const;
    
    void update(sf::Time delta);

protected:
    void changeDirection();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite m_visual;
    PacWoman* m_pacWoman;

    bool m_isWeak;
    sf::Time m_weaknessDuration;

    Animator m_strongAnimator;
    Animator m_weakAnimator;
};

#endif  // !PACWOMAN_GHOST_H