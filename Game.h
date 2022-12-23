#pragma once
#include "Map.h"
#include "Data.h"
#include <string>
#include <iostream>


class Game
{
public:
	Game():currantmap(NULL){};
	~Game() { delete currantmap; };

public:
	void upload_map(string name);
    void add_room(Room& room){data.add_room(room);};
    void print_rooms_data(){data.print_rooms();};
    int get_data_size(){return data.get_map_size();};

private:
	Map* currantmap;
	Data data;
};

