#pragma once
#include "Room.h"
#include <iostream>
#include <string>


class Map
{
public:
    Map();
	Map(Map& source);
	Map(string name):name(name),rooms(NULL),curr_room(NULL),numberofrooms(0) {};
	~Map();

public:
	Map& operator=(Map& source);
    Map& operator+=(Map& source);
    void add_room( Room& room, direction dir );
    Map operator+(Map& map);
	string get_name() { return name; };
	Room* get_room(string name) { return rooms->find_room(name); };
    int room_count(){return rooms->room_count();};
	void print_rooms() { rooms->print_rooms(); };
private:
	std::string name;
    int numberofrooms;
	Room* rooms;
    Room* curr_room;

};

