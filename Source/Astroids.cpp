#include "SMFL/Header/Astroids.h"

void Astroids::initilizeWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "Most Epic Remake of Astroids with SMFL", sf::Style::Close | sf::Style::Titlebar);
}
Astroids::Astroids() {

}

Astroids::~Astroids() {
    delete this->window;
}

//Function
void Astroids::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Astroids::update() {

}

void Astroids::render(){
    this->window->clear();

    //Draws all the stuff
    this->window->display();
}