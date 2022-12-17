#pragma once
#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
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
	bool Add_Room(Room* source, direction direction );
	string& get_name() { return m_name; };
	Room* find_room(string& room);
	bool checkroom( direction direction);
	Room* copy_rooms(Room*& room);
	Room* delete_room(Room& room);
    Room* move_room(direction direction);
private:
	int num_of_item;
	int num_of_monster;
	string m_name;
	Item* m_item;
	Monster* m_monster;
	Room* m_North;
	Room* m_South;
	Room* m_East;
	Room* m_West;
	bool visited = false;
};

