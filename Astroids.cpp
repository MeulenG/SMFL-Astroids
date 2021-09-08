#include "Astroids.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

// this is our window function with a resolution of 800x800 and you can close, resize it and it has a title bar. 120 FPS, no Vsync
void Astroids::initilizeWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Most Epic Remake of Astroids with SMFL", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
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

    //Player
    this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));
    
    this->playerHpBack = this->playerHpBar;
    this->playerHpBack.setFillColor(sf::Color(25, 25, 25, 200));


}

void Astroids::intilizeWorld() {
    if(this->worldBackGroundTex.loadFromFile("/home/puhaa/Desktop/SMFL-Astroids/images/background1920x1080.png")) {
        std::cout << "ERROR COULD NOT LOAD WORLDBACKGROUND";
    }
    this->worldBackground.setTexture(this->worldBackGroundTex);
    
}

void Astroids::intilizeSystems() {
    this->points = 0;

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
    this->intilizeWorld();
    this->intilizeSystems();
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
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width/2.f, this->player->getPos().y, 0.f, -1.f, 4.f));
    }
}

void Astroids::updateGUI() {
    std::stringstream ss;

    ss << "Points: " << this->points;

    this->pointText.setString(ss.str());


    //Update Player GUI

    this->player->setHp(5);
    float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
    this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

}

void Astroids::updateWorld() {


}

void Astroids::updateCollision() {
    //Left WOrld Collision
    if (this->player->getBounds().left < 0.f)
    {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }
    //Right World Collision
    else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
    {
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
    }


    //Top World Collision
    if (this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
    //Bottom World Collision
    else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
    {
        this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
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

void Astroids::updateEnemies() {



    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));
        this->spawnTimer = 0.f;

    }

    unsigned counter = 0;
    for (auto *enemy : this->enemies)
    {
        enemy->update();


        //Bullet culling (top of screen)
        if(enemy->getBounds().top > this->window->getSize().y) 
        {
            //Deletes bullets
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin()+ counter);
            --counter;
        }

        else if (enemy->getBounds().intersects(this->player->getBounds())) {
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin()+ counter);
            --counter;
        }
        ++counter;
    }



}

void Astroids::updateCombat() {

    for (int i = 0; i < this->enemies.size(); ++i)
    {
        bool enemy_deleted = false;
        for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
        {
            if(this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {

                this->points += this->enemies[i]->getPoints();

                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);


                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);
                

                enemy_deleted = true;
            }
        }
        
    }

}


void Astroids::update() {
    
    this->updatePollEvents();

    this->updateInput();

    this->player->update();

    this->updateCollision();

    this->updateBullets();

    this->updateEnemies();

    this->updateCombat();

    this->updateGUI();

    this->updateWorld();
    
    
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
    this->window->draw(this->playerHpBack);
    this->window->draw(this->playerHpBar);

}

void Astroids::renderWorld() {
    this->window->draw(this->worldBackground);
}


void Astroids::render(){
    this->window->clear();

    this->renderWorld();

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