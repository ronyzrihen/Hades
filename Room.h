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
	Room(string name);
	~Room();

public:
	Room& operator=(Room& source);
	bool Add_Room(Room* source, direction direction );
	string& get_name() { return m_name; };
	Room* find_room(string& room);
	bool check_room(Room& room, direction direction);
	bool check_room( direction direction);
    Room* copy_rooms(Room& room);
	Room* delete_room();
    Room* move_room(direction direction);

    void set_North(Room& room){*m_North = room;}; //copies an existing room
    void set_West(Room& room){*m_West = room;};
    void set_East(Room& room){*m_East = room;};
    void copy_South(Room& room){m_South = new Room(room); };

    void set_North(Room* room){m_North = room;}; //connects an existing room
    void set_West(Room* room){m_West = room;};
    void set_East(Room* room){m_East = room;};
    void set_South(Room* room){m_South = room;};
	

    void add_item(Item& item);
	void print_rooms();


    Room* get_North(){return m_North;};
    Room* get_West(){return m_West;};
    Room* get_East(){return m_East;};
    Room* get_South(){return m_South;};
   friend ostream& operator <<(ostream&out,Room&room);
   void print();
    int room_count();

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

std:: ostream& operator <<(ostream& out, Room& room);