#include <SFML/Graphics.hpp>
#ifndef PLAYER_H
#define PLAYER_H
 class Player {

private:
    sf::Sprite Sprite;
    sf::Texture texture;
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

    void move(const float dirX, const float dirY);
    const bool canAttack();


    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};
#endif