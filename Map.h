#pragma once
#include "Room.h"
#include <iostream>
#include <string>


class Map
{
public:
	Map(Map& source);
	~Map();

public:
	Map& operator=(Map& source);
    Map& operator+=(Map& source);
	//todo delete - Room* copy(Room*& rooms) { return rooms->copy_rooms(rooms); };
    void add_room( Room& room, direction dir );
    Map operator+(Map& map);

private:
	std::string name;
	std:: string* room_names;
    int numberofrooms;
	Room* rooms;
    Room* curr_room;

};

