#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
class Bullet
{
private:
    sf::Sprite shape;

    sf::Vector2f direction;
public:
    Bullet(/* args */);
    ~Bullet();

    float movementSpeed;
    Bullet(sf::Texture * texture, float posX, float posY, float dirX, float dirY, float movement_speed);


    const sf::FloatRect getBounds() const;


    void update();
    void render(sf::RenderTarget* target);
};

Bullet::Bullet(/* args */)
{
}

Bullet::~Bullet()
{
}
#endif