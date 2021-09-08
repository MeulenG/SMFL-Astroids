#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
class Enemy
{
private:
    unsigned pointcount;
    sf::CircleShape shape;

    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;

    
    void initVariables();
    void initShape();

public:
    Enemy(float posX, float posY);
    ~Enemy();

    const sf::FloatRect getBounds() const;
    const int& getPoints() const;

    void update();
    void render(sf::RenderTarget* target);
};



#endif