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
    void add_room_to_data(Room& room){data.add_room(room);};
    void add_to_current(Room* room);
	void add_map(const Map& map) { data.add_map(map); };
    void print_rooms_data(){data.print_rooms();};
    int get_data_size(){return data.get_map_size();};
	void print_map_data() { data.print_map(); };
	int get_num_of_rooms() { return currantmap->room_count(); };
	string print_current() {return currantmap->get_name(); };

	Map* get_map(string name) { return data.getmap(name); };
    Room* get_room(const string& room){return data.getroom(room);}

	Map& get_current() { return *currantmap; };
    Room& get_curr_room(){return currantmap->get_curr();};
	
private:
	Map* currantmap;
	Data data;
};

