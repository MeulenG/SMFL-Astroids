#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#ifndef PLAYER_H
#define PLAYER_H
 class Player {

private:
    sf::Sprite Sprite;
    sf::Texture texture;
    
    void initTexture();
    void initSprite();
public:
    Player();
    ~Player();

    float movementspeed;

    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
};
#endif