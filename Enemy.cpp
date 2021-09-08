#include <iostream>
#include "Enemy.h"



void Enemy::initVariables() {
    this->pointcount = rand()% 8 + 3;
    this->type      = 0;
    this->speed     = static_cast<float>(this->pointcount/3);
    this->hp        = this->hpMax;
    this->hpMax     = static_cast<int>(this->pointcount);
    this->damage    = this->pointcount;
    this->points    = this->pointcount;
}


void Enemy::initShape() {
    this->shape.setRadius(this->pointcount * 5);
    this->shape.setPointCount(this->pointcount);
    this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}




Enemy::Enemy(float posX, float posY)
{
    
    this->initVariables();
    this->initShape();

    this->shape.setPosition(posX, posY);
}


Enemy::~Enemy()
{
    
}

const sf::FloatRect Enemy::getBounds() const {

    return this->shape.getGlobalBounds();

}

const int & Enemy::getPoints() const {
    return this->points;
}


void Enemy::update() {
    this->shape.move(0.f, this->speed);
}


void Enemy::render(sf::RenderTarget * target) {
    target->draw(this->shape);

}