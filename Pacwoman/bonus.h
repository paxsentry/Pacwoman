#ifndef PACWOMAN_BONUS_H
#define PACWOMAN_BONUS_H

#include <SFML\Graphics.hpp>

class Bonus : public sf::Drawable, public sf::Transformable
{
public:
    Bonus(sf::Texture& texture);
    ~Bonus();

    enum Fruit
    {
        Banana,
        Apple,
        Cherry
    };

    void setFruit(Fruit fruit);

private:
    sf::Sprite m_visual;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif  // !PACWOMAN_BONUS_H