#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
class Enemy
{
private:
    sf::CircleShape shape;

    int type;
    int hp;
    int hpMax;
    int damage;
    int points;

    void initShape();
    void initVariables();

public:
    Enemy(float posX, float posY);
    ~Enemy();

    void update();
    void render(sf::RenderTarget* target);
};



#endif