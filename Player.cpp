#include "Player.h"
#include <iostream>
#include "stdio.h"

void Player::initVariables() {
    this->movementspeed = 2.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;

    this->hpMax = 10;
    this->hp = this->hpMax;
}



void Player::initTexture() {
    if(!this->texture.loadFromFile("/home/puhaa/Desktop/SMFL-Astroids/images/Asteroid Spaceship.png"))
     {
         std::cout << "failed to load picture!";
     }
}

void Player::initSprite() {
    this->Sprite.setTexture(this->texture);

    this->Sprite.scale(0.3f, 0.3f);
}

Player::Player()
{
    initVariables();
    this->initTexture();
    this->initSprite();
}
Player::~Player() {

}

const sf::Vector2f& Player::getPos() const 
{
    return this->Sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const {

    return this->Sprite.getGlobalBounds();
}

const int& Player::getHp() const {
    return this->hp;

}
const int& Player::getHpMax() const {
    return this->hpMax;


}

void Player::setPosition(const sf::Vector2f pos) {
    this->Sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y) {
    this->Sprite.setPosition(x,y);
}

void Player::setHp(const int hp) {
    this->hp = hp;

}

void Player::loseHp(const int value) {

    this->hp -= value;
}


void Player::move(const float dirX, const float dirY) {
    this->Sprite.move(this->movementspeed * dirX, this->movementspeed * dirY);
}

const bool Player::canAttack() 
{
    if (this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    
    return false;
}


void Player::updateAttack() 
{
    if(this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 0.5f;
}


void Player::update() 
{
    this->updateAttack();
}

void Player::render(sf::RenderTarget& target) {
    target.draw(this->Sprite);
}