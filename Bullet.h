#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Bullet
{
private:
    sf::Sprite shape;
    
    sf::Vector2f direction;
    void initBullet();
public:
    Bullet(/* args */);
    ~Bullet();

    float movementSpeed;
    Bullet(sf::Texture * texture, float pos_x, float pos_y, float dirX, float dirY, float movement_speed);


    const sf::FloatRect getBounds() const;


    void update();
    void render(sf::RenderTarget* target);
};
#endif