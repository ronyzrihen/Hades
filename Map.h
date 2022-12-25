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
	Map& operator=(const Map& source);


    Map& operator+=( Map& source);
    Map operator+(Map& map);
    void add_room( Room& room, direction dir );
    void add_to_curr(Room* room){curr_room->Add_Room(room);};
	string get_name() { return name; };
    Room& get_curr(){return *curr_room;};
	Room* get_room(string name) { return rooms->find_room(name); };
    int room_count(){return rooms->room_count();};
	void print_rooms() { rooms->print_rooms(); };
private:
	std::string name;
    int numberofrooms;
	Room* rooms;
    Room* curr_room;

};

