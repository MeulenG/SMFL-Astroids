#ifndef ASTROIDS_H
#define ASTROIDS_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <map>
#include "Enemy.h"
#include <string>
#include <sstream>


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


    //Player GUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBack;


    //Systems
    unsigned points;

    //World
    sf::Texture worldBackGroundTex;
    sf::Sprite worldBackground;


    void initilizeWindow();
    void initilizeTextures();
    void intilizeGUI();
    void intilizeWorld();
    void intilizeSystems();
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
        void updateWorld();
        void updateCollision();
        void updateBullets();
        void updateEnemies();
        void updateCombat();
        void update();
        void renderGUI();
        void renderWorld();
        void render();
};
#endif