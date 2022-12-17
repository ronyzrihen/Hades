#pragma once
#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <string>

typedef enum {
	north,
	south,
	east,
	west
}direction;

class Room
{
public:
	Room();
	Room(Room& source);
	~Room();

public:
	Room& operator=(Room& source);
	bool Add_Room(Room& source, direction direction );
	std::string get_name() { return m_name; };
	Room* find_room(Room& room);
	//bool checkroom(const Room& room, direction direction);
	Room* copy_rooms(Room*& room);
	Room& delete_room(Room& room);
private:
	int num_of_item;
	int num_of_monster;
	std::string m_name;
	Item* m_item;
	Monster* m_monster;
	Room* m_North;
	Room* m_South;
	Room* m_East;
	Room* m_West;
	bool visited = false;
};

