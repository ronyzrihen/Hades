#pragma once
#include "Room.h"
#include <iostream>
#include <string>


class Map
{
public:
	Map(Room& source);
	~Map();

public:
	Map& operator=(Map& source);
	Room* copy(Room*& rooms) { return rooms.copy_rooms(rooms); };
private:
	std::string name;
	Room* rooms;
	int numberofrooms;
};

