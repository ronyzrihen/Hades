#pragma once
#include "Map.h"
#include "Data.h"




class Game
{
public:
	Game();
	~Game();

private:
	Map* currantmap;
	Data data;
};

Game::Game()
{
}

Game::~Game()
{
}
