all: compile link

compile:
	g++ -I C:\Libraries\SFML-2.5.1\include -c main.cpp

link:
	g++ main.o -o main -L C:\Libraries\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system