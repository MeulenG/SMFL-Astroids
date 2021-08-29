#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#ifndef ASTROIDS_H
#define ASTROIDS_H
class Astroids {
    private:
    sf::RenderWindow* window;

    Player * player;

    void initilizeWindow();
    void initilizePlayer();
    public:
        Astroids();
        virtual ~Astroids();
        //Function
        void run();

        void update();
        void render();
};
#endif