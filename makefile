compile:
	g++ -c main.cpp Player.cpp Bullet.cpp Astroids.cpp Enemy.cpp
	g++ main.o Player.o Bullet.o Astroids.o Enemy.o -o smfl-app -lsfml-graphics -lsfml-window -lsfml-system
run:
	./smfl-app