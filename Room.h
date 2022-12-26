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
	
	Room* find_room(string& room);
	bool check_room(Room& room, direction direction);
	bool check_room( direction direction);
	Room* delete_room();
    Room* move_room(direction direction);


    Room* copy_rooms(Room* prev);
     void copy_South(Room& room){m_South = new Room(room); };
//setters 
    void set_North(Room* room){m_North = room;}; //connects an existing room
    void set_West(Room* room){m_West = room;};
    void set_East(Room* room){m_East = room;};
    void set_South(Room* room){m_South = room;};
    void set_name(string name){m_name = name;};
	

	bool Add_Room(Room* source, direction direction);
	bool Add_Room(Room* source);
    void add_item(Item& item);
	void add_monster(Monster& monster);

	//getters
	string& get_name() { return m_name; };
    Room* get_North(){return m_North;};
    Room* get_West(){return m_West;};
    Room* get_East(){return m_East;};
    Room* get_South(){return m_South;};
    int room_count();
   
	//printing functions
	void print_rooms();
   void print();
   friend ostream& operator <<(ostream&out,Room&room);

private:
	int num_of_item;
	int num_of_monster;
	string m_name;
	Item** m_item;
	Monster** m_monster;
	Room* m_North;
	Room* m_South;
	Room* m_East;
	Room* m_West;
	bool visited = false;
};

std:: ostream& operator <<(ostream& out, Room& room);