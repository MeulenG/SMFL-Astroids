#ifndef ASTROIDS_H
#define ASTROIDS_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <map>
#include "Enemy.h"


class Astroids {
    private:
    sf::RenderWindow* window;

    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;
    
    
    Player* player;

    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy* > enemies;

    void initilizeWindow();
    void initilizeTextures();
    void initilizePlayer();
    void initilizeEnemies();
    
    public:
        Astroids();
        ~Astroids();
        //Function
        void run();

        void updatePollEvents();
        void updateInput();
        void updateBullets();
        void updateEnemies();
        void update();
        void render();
};
#endif