compile:
	g++ -c main.cpp
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

run: compile
	./main

