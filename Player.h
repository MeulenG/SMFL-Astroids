#include <SFML/Graphics.hpp>
#ifndef PLAYER_H
#define PLAYER_H
 class Player {

private:
    sf::Sprite Sprite;
    sf::Texture texture;
    
    int hp;
    int hpMax;
    
    
    void initVariables();
    void initTexture();
    void initSprite();

    
public:
    Player();
    ~Player();

    float movementspeed;
    float attackCooldown;
    float attackCooldownMax;
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    const int& getHp() const;
    const int& getHpMax() const;

    //Modify
    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);
    void setHp(const int hp);
    void loseHp(const int value);

    void move(const float dirX, const float dirY);
    const bool canAttack();


    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};
#endif