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

    //GUI
    sf::Font font;
    sf::Text pointText;

    void initilizeWindow();
    void initilizeTextures();
    void intilizeGUI();
    void initilizePlayer();
    void initilizeEnemies();
    
    public:
        Astroids();
        ~Astroids();
        //Function
        void run();

        void updatePollEvents();
        void updateInput();
        void updateGUI();
        void updateBullets();
        void updateEnemiesAndCombat();
        void update();
        void renderGUI();
        void render();
};
#endif