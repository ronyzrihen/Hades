#pragma once
#include "Map.h"
#include "Room.h"
#include <iostream>
#include <string>



class Data
{
public:
	Data() :mapsdata(NULL), roomsData(NULL),mapsize(0),roomsize(0) {};
	~Data(){};

public:
	void add_map(Map& map);
	void add_room(Room& room);
	Room* getroom(string name);
	Map* getmap(string name);
    int get_room_size(){return roomsize;};
    int get_map_size(){return mapsize;};
    void print_rooms();
	void print_map();
private:
	Map** mapsdata;
	Room** roomsData;
	int mapsize;
	int roomsize;
};


