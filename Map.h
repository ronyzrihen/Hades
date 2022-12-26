#pragma once
#include "Room.h"
#include <iostream>
#include <string>


class Map
{
public:
    Map();
	Map(const Map& source);
	Map(string name):name(name),rooms(NULL),curr_room(NULL),numberofrooms(0) {};
	~Map();

public:
    int room_count(){return rooms->room_count();};
	void print_rooms() { rooms->print_rooms(); };

	//Operators
	Map& operator=(const Map& source);
    Map& operator+=( Map& source);
    Map operator+(Map& map);

	//adders
    void add_room( Room& room, direction dir );
	void add_to_curr(Room* room) { if (curr_room->Add_Room(room)) { cout << room->get_name() << "Was added\n"; }; };
	
	//getters
	string get_name() { return name; };
    Room& get_curr(){return *curr_room;};
	Room* get_room(string name) { return rooms->find_room(name); };
	
private:
	std::string name;
    int numberofrooms;
	Room* rooms;
    Room* curr_room;

};

