#pragma once
#include "Map.h"
#include "Data.h"




class Game
{
public:
	Game():currantmap(NULL){};
	~Game() { delete currantmap; };

public:
	void upload_map(string name);

private:
	Map* currantmap;
	Data data;
};

