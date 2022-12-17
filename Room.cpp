#include "Room.h"
using namespace std;

Room::Room()
	:
	num_of_item(0),
	num_of_monster(0),
	m_name(NULL),
	m_item(NULL),
	m_monster(NULL),
	m_North(NULL),
	m_South(NULL),
	m_East(NULL),
	m_West(NULL)
{}

Room::Room(Room& source) :
num_of_item(source.num_of_item),
num_of_monster(source.num_of_monster),
m_name(source.m_name),
m_item(new Item[source.num_of_item]),
m_monster(new Monster[source.num_of_monster]),
m_North(source.m_North),
m_South(source.m_South),
m_East(source.m_East),
m_West(source.m_West)
{
	for (int i = 0; i < num_of_item; i++) {
		m_item[i] = source.m_item[i];
	}
	for (int i = 0; i < num_of_monster; i++) {
		m_monster[i] = source.m_monster[i];
	}

	if (source.m_North == NULL)
		return;

	if (source.m_North != NULL) {
		m_North = Room(source.m_North);
	}
}

Room& Room:: operator=(Room& source) {

	if (this == &source)
		return *this;

	if (num_of_item == source.num_of_item) {
		for (int i = 0; i < num_of_item; i++)
			m_item[i] = source.m_item[i];
	}
	else {
		delete[]m_item;

		m_item = new Item[source.num_of_item];
		for (int i = 0; i < source.num_of_item; i++)
		{
			m_item[i] = source.m_item[i];
		}

		if (num_of_monster == source.num_of_monster) {

			for (int i = 0; i < num_of_monster; i++)
			{
				m_monster[i] = source.m_monster[i];
			}
		}
		else
		{
			delete[]m_monster;
			for (int i = 0; i < source.num_of_monster; i++)
			{
				m_monster[i] = source.m_monster[i];
			}
		}
	
		m_name = source.m_name;

		delete[] m_North;
		m_North = new Room(*(source.m_North));

		delete[] m_South;
		m_South = new Room(*(source.m_South));

		delete[] m_East;
		m_East = new Room(*(source.m_East));

		delete[] m_West;
		m_West = new Room(*(source.m_West));

		num_of_item = source.num_of_item;
		num_of_monster = source.num_of_item;
	}
}
	bool Room::Add_Room(Room & source, direction direction){

		if (find_room(source) != NULL) {
			cout << "Room Already exist\n";
			return false;
		}


		switch (direction) {

		case 0: {
			if (m_North != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_North = new Room(source);
			m_North->m_South = this;


			break;
		}

		case 1: {
			if (m_South != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_South = new Room(source);
			m_South->m_North = this;
			break;
		}
		case 2: {
			if (m_East != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_East = new Room(source);
			m_East->m_West = this;
			break;
		}
		case 3: {
			if (m_West != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_West = new Room(source);
			m_West->m_East = this;
			break;
		}
			  return true;
		}///switch
		
	}


	Room* Room::find_room(Room& room) {
		Room* North = NULL;
		Room* South = NULL;
		Room* East = NULL;
		Room* West = NULL;

		if (visited == true)
			return NULL;
		if (m_name == room.m_name) 
			return this;
		
		if (m_North != NULL)
			North=m_North->find_room(room);

		if (m_South != NULL)
			South = m_South->find_room(room);

		if (m_East != NULL)
			East= m_East->find_room(room);

		if (m_West!= NULL)
			West = m_West->find_room(room);

		visited = false;

		if (North!= NULL)
			return North;

		if (South != NULL)
			return South;

		if (East != NULL)
			return East;

		if (West != NULL)
			return West;

		return NULL;
	}





	Room* Room:: copy_rooms(Room*& room) {

		if (this == NULL)
			return NULL;

		if (visited == true)
			return this;

		visited = true;

		Room* new_rooms = new Room(*this);

		new_rooms->num_of_item = room->num_of_item;
		new_rooms->num_of_monster = room->num_of_monster;

		for (int i = 0; i < room->num_of_item; i++) {
			new_rooms->m_item[i] = room->m_item[i];
		}
		for (int i = 0; i < room->num_of_monster; i++) {
			new_rooms->m_monster[i] = room->m_monster[i];
		}

		new_rooms->m_West = copy_rooms(room->m_West);

		new_rooms->m_East = copy_rooms(room->m_East);

		new_rooms->m_North = copy_rooms(room->m_North);

		new_rooms->m_South = copy_rooms(room->m_South);

		visited = false;

		return new_rooms;



	}



	Room& Room:: delete_room(Room&room) {
		if (m_North->m_North == NULL) {
			
			return NULL ;
		}

	}