#include <SFML/Graphics.hpp>
#include "Astroids.h"
#include <time.h>


int main()
{   
    srand(time(static_cast<unsigned>(0)));



    Astroids astroids;
    astroids.run();
}


