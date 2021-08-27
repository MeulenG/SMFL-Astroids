#include <SFML/Graphics.hpp>
#include "SMFL-Astroids/Header/Astroids.h"
#include "SMFL-Astroids/Header/Player.h"


int main()
{
    Astroids astroids;
    astroids.run();
    
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.display();
    }

    return 0;
}