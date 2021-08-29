#include "Astroids.h"
#include "Player.h"

void Astroids::initilizeWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Most Epic Remake of Astroids with SMFL", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Astroids::initilizePlayer() {
    this->player = new Player();
}
Astroids::Astroids() {
    this->initilizeWindow();
    this->initilizePlayer();
}

Astroids::~Astroids() {
    delete this->window;
    delete this->player;
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
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == sf::Event::Closed)
        
            this->window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();      
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);
        
        
    
    
}

void Astroids::render(){
    this->window->clear();

    //Draws all the stuff
    this->player->render(*this->window);
    this->window->display();
}