#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Astroids {
    private:
    sf::RenderWindow* window;

    void initilizeWindow();
    public:
        Astroids();
        virtual ~Astroids();
        //Function
        void run();

        void update();
        void render();
};