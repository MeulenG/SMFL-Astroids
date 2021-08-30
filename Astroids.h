#ifndef ASTROIDS_H
#define ASTROIDS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Bullet.h"
#include <map>


class Astroids {
    private:
    sf::RenderWindow* window;

    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;
    
    
    Player* player;

    void initilizeWindow();
    void initilizeTextures();
    void initilizePlayer();
    
    public:
        Astroids();
        virtual ~Astroids();
        //Function
        void run();

        void updatePollEvents();
        void updateInput();
        void updateBullets();
        void update();
        void render();
};
#endif