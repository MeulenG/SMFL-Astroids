#include "Bullet.h"


Bullet::Bullet() {

}

Bullet::Bullet(sf::Texture * texture, float posX, float posY, float dirX, float dirY, float movement_speed) {
    this->shape.setTexture(*texture);

    this->shape.setPosition(posX, posY);
    this->direction.x = dirX;
    this->direction.y = dirY;
    this->movementSpeed = movement_speed;
}

Bullet::~Bullet() {

}

const sf::FloatRect Bullet::getBounds() const {
    
    return this->shape.getGlobalBounds();
}

void Bullet::update() {
    this->shape.move(this->movementSpeed * this->direction);

}

void Bullet::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}