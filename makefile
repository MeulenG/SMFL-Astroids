compile:
	g++ -c main.cpp Astroids.cpp Player.cpp
	g++ main.o Astroids.o Player.o -o smfl-app -lsfml-graphics -lsfml-window -lsfml-system
run:
	./smfl-app