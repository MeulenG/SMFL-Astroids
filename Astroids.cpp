#include "Astroids.h"
#include "Player.h"
#include "Bullet.h"

// this is our window function with a resolution of 800x800 and you can close, resize it and it has a title bar. 120 FPS, no Vsync
void Astroids::initilizeWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Most Epic Remake of Astroids with SMFL", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Astroids::initilizeTextures() {
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("/home/puhaa/Desktop/SMFL-Astroids/images/Bullet3.png");
    
}


void Astroids::initilizePlayer() {
    this->player = new Player();
}
Astroids::Astroids() {
    this->initilizeWindow();
    this->initilizeTextures();
    this->initilizePlayer();
}


Astroids::~Astroids() {
    delete this->window;
    delete this->player;
    //deletes textures
    for (auto &i : this->textures)
    {
        delete i.second;
    }
    //deletes bullets
    for (auto *i : this->bullets)
    {
        delete i;
    }
    
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
void Astroids::updatePollEvents() {


}


void Astroids::updateInput() {
        // Moves the player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 1.f));
    }
}

void Astroids::updateBullets() 
{
    unsigned counter = 0;
    for (auto *bullet : this->bullets)
    {
        bullet->update();


        //Bullet culling (top of screen)
        if(bullet->getBounds().top + bullet->getBounds().height < 0.f) 
        {
            //Deletes bullets
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+ counter);
            --counter;
        }
        ++counter;
    }

}


void Astroids::update() {
    
    this->updatePollEvents();

    this->updateInput();

    this->player->update();

    this->updateBullets();
    
    
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == sf::Event::Closed)
        
            this->window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();      
        
    }

    
        
    
    
}

void Astroids::render(){
    this->window->clear();

    //Draws all the stuff
    this->player->render(*this->window);

    for (auto *bullet : this->bullets)
    {
        bullet->render(this->window);
    }
    

    this->window->display();
}