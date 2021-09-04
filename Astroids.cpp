#include "Astroids.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

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

void Astroids::intilizeGUI() {
    //Loads our Font
    if(!this->font.loadFromFile("/home/puhaa/Desktop/SMFL-Astroids/images/PixellettersFull.ttf"))
        std::cout << "ERROR AT FONT";

    //Intilize Point Text
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(12);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("test");

}




void Astroids::initilizePlayer() {
    this->player = new Player();
    
}

void Astroids::initilizeEnemies() {
    this->spawnTimerMax = 20.f;
    this->spawnTimer = this->spawnTimerMax;

}

Astroids::Astroids() {
    this->initilizeWindow();
    this->initilizeTextures();
    this->intilizeGUI();
    this->initilizePlayer();
    this->initilizeEnemies();
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
    
    for (auto *i : this->enemies)
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->player->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack()) {
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width/2.f, this->player->getPos().y, 0.f, -1.f, 1.f));
    }
}

void updateGUI() {



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

void Astroids::updateEnemiesAndCombat() {
    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));
        this->spawnTimer = 0.f;

    }



    for (int i = 0; i < this->enemies.size(); ++i)
    {
        bool enemy_removed = false;
        this->enemies[i]->update();
        for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++)
    {
        if(this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds()))
        {
            this->bullets.erase(this->bullets.begin() + k);
            this->enemies.erase(this->enemies.begin() + i);
            enemy_removed = true;
        }
    }
    if(!enemy_removed)
    {
        if(this->enemies[i]->getBounds().top > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            enemy_removed = true;
        }
    }
}


}



void Astroids::update() {
    
    this->updatePollEvents();

    this->updateInput();

    this->player->update();

    this->updateBullets();

    this->updateEnemiesAndCombat();

    this->updateGUI();
    
    
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == sf::Event::Closed)
        
            this->window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();      
        
    }

    
        
    
    
}

void Astroids::renderGUI() {
    this->window->draw(this->pointText);

}


void Astroids::render(){
    this->window->clear();

    //Draws all the stuff
    this->player->render(*this->window);

    for (auto *bullet : this->bullets)
    {
        bullet->render(this->window);
    }

    for (auto *enemy : this->enemies)
    {
        enemy->render(this->window);
    }

    this->renderGUI();
    
    this->window->display();
}