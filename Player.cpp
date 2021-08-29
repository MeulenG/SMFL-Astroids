#include "Player.h"
#include <iostream>
#include "stdio.h"

void Player::initTexture() {
    if(!this->texture.loadFromFile("/home/puhaa/Desktop/SMFL-Astroids/images/Asteroid Spaceship.png"))
     {
         std::cout << "failed to load picture!";
     }
}

void Player::initSprite() {
    this->Sprite.setTexture(this->texture);

    this->Sprite.scale(0.1f, 0.1f);
}

Player::Player()
{
    this->movementspeed = 1.f;
    this->initTexture();
    this->initSprite();
}
Player::~Player() {

}
void Player::move(const float dirX, const float dirY) {
    this->Sprite.move(this->movementspeed * dirX, this->movementspeed * dirY);
}
void Player::update() {

}

void Player::render(sf::RenderTarget& target) {
    target.draw(this->Sprite);
}