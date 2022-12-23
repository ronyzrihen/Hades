#include "Room.h"
using namespace std;

Room::Room()
	:
	num_of_item(0),
	num_of_monster(0),
	m_name(" "),
	m_item(NULL),
	m_monster(NULL),
	m_North(NULL),
	m_South(NULL),
	m_East(NULL),
	m_West(NULL)
{}

Room::Room(Room& source) :
m_North(NULL),
m_South(NULL),
m_East(NULL),
m_West(NULL)

{
	for (int i = 0; i < num_of_item; i++) {
		m_item[i] = source.m_item[i];
	}
	for (int i = 0; i < num_of_monster; i++) {
		m_monster[i] = source.m_monster[i];
	}
    m_name = source.m_name;
    num_of_item = source.num_of_item;
    num_of_monster = source.num_of_monster;
    source.visited = true;

    if(source.m_North != NULL)
        m_North = source.m_North->copy_rooms(*(source.m_North));
    if(source.m_South != NULL)
        m_South = source.m_South->copy_rooms(*(source.m_South));
    if(source.m_East!= NULL)
        m_East = source.m_East->copy_rooms(*(source.m_East));
    if(source.m_West != NULL)
        m_West = source.m_West->copy_rooms(*(source.m_West));
source.visited = false;
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
        for (int i = 0; i < source.num_of_item; i++) {
            m_item[i] = source.m_item[i];
        }
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
        num_of_item = source.num_of_item;
        num_of_monster = source.num_of_monster;
        visited = false;


    delete m_North;
    if(m_East != NULL)
        delete m_East;
    if(m_South != NULL)
        delete m_South;
    if(m_West != NULL)
        delete m_West;


		return *this;
    }


	bool Room::Add_Room(Room * source, direction direction){

		if (this->find_room(source->get_name()) != NULL) {
			cout << "Room Already exist\n";
			return false;
		}


		switch (direction) {

		case 0: {
			if (m_North != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_North = source;
			m_North->m_South = this;


			break;
		}

		case 1: {
			if (m_South != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_South = source;
			m_South->m_North = this;
			break;
		}
		case 2: {
			if (m_East != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_East = source;
			m_East->m_West = this;
			break;
		}
		case 3: {
			if (m_West != NULL) {
				cout << "Room is taken\n";
				return false;
			}
			m_West = source;
			m_West->m_East = this;
			break;
            }
            default:{
                cout << "Error!\n";
                return false;
            }
		}///switch
			  return true;

	}


	Room* Room::find_room(string& room) {
		Room* North = NULL;
		Room* South = NULL;
		Room* East = NULL;
		Room* West = NULL;

        if(this == NULL)
            return NULL;

		if (visited == true)
			return NULL;
        cout << m_name << endl;
		if (m_name == room)
			return this;
		visited = true;
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





	Room* Room:: copy_rooms(Room& room) {

		if (this == NULL )
			return NULL;

		if (visited == true)
			return this;

        Room* new_room = new Room;

        new_room->m_name = room.m_name;
        new_room->num_of_item = room.num_of_item;
        new_room->num_of_monster = room.num_of_monster;

		for (int i = 0; i < room.num_of_item; i++) {
            new_room->m_item[i] = room.m_item[i];
		}
		for (int i = 0; i < room.num_of_monster; i++) {
            new_room->m_monster[i] = room.m_monster[i];
		}
		visited = true;


		m_West = room.m_West->copy_rooms(*room.m_West);

		m_East = room.m_East->copy_rooms(*room.m_East);

		m_North = room.m_North->copy_rooms(*room.m_North);

		m_South = room.m_South->copy_rooms(*room.m_South);


		visited = false;

		return this;



	}



	Room* Room:: delete_room() {
		if (this == NULL)
			return NULL ;
        if(visited)
            return this;
        visited= true;
        m_North = m_North->delete_room();
        m_South=m_South->delete_room();
        m_East=m_East->delete_room();
        m_West=m_West->delete_room();
        return NULL;

	}

bool Room::check_room( Room& room, direction direction){
    switch (direction){
        case north:{
            if (room.check_room(north) == NULL)

                return true;
            break;
        }
        case west:{
            if (room.check_room(west) == NULL)
                return true;
            break;
        }
        case east:{
            if  (room.check_room(east) == NULL)
                return true;
            break;
        }
        case south:{
            if (room.check_room(south) == NULL)
                return true;
            break;
        }
        default: {
            cout << "Invalid direction\n";
            return false;
        }
    }// end of switch
    return false;
}
bool Room::check_room( direction direction) {
    switch (direction) {
        case north: {
            if (m_South == NULL)
                return true;
            break;
        }
        case west: {
            if (m_East == NULL)
                return true;
            break;
        }
        case east: {
            if (m_West == NULL)
                return true;
            break;
        }
        case south: {
            if (m_North == NULL)
                return true;
            break;
        }
        default: {
            cout << "Invalid direction\n";
            return false;
        }
    }// end of switch
    return false;
}



Room* Room:: move_room(direction direction){

    switch (direction){
        case north: {
            if (m_North != NULL)
                return m_North;
                break;
            }
            case west: {
                if (m_West != NULL)
                    return  m_West;
                break;
                }
                case east: {
                    if (m_East != NULL)
                        return m_East;

                        break;
                    }
                    case south: {
                        if (m_South != NULL)
                            return m_South;

                        break;
                        }

                    }
                    return this;
                }

void Room:: add_item(Item& item){
    Item* new_item_list = NULL;
    for(int i = 0 ; i <  num_of_item ; i++){
        if (m_item[i].get_name() == item.get_name()){
            if(m_item[i].get_rarity() + (item).get_rarity() > legendary){
                m_item[i] += item;

                new_item_list = new Item[num_of_item+1];
                for(int i = 0 ; i < num_of_item ; i++){
                    new_item_list[i] = m_item[i];
                }
                new_item_list[num_of_item+1] = item;
                num_of_item++;
                delete [] m_item;
                m_item = new_item_list;

                m_item[num_of_item].set_rarity(common);

                return;
            }
            m_item[i] += item;
			return;
        }
        new_item_list = new Item[num_of_item+1];
        for(int i = 0 ; i < num_of_item; i++){
            new_item_list[i] = m_item[i];
        }
        new_item_list[num_of_item+1] = item;
        num_of_item++;
        return;
    }


}


void Room::print() {

	cout << m_name << endl;

	for (int i = 0; i < num_of_item; i++)
	{
		cout << m_item[i].get_name() << endl;
	}
	for (int i = 0; i < num_of_monster; i++)
	{
		cout << m_monster[i].get_name() << endl;
	}
	cout << "in the north - " << (m_North == NULL?"No room":m_North->get_name()) << endl
		<< "in the south - " << (m_South == NULL ? "No room" : m_South->get_name()) << endl
		<< "in the east - " << (m_East == NULL ? "No room" : m_East->get_name()) << endl
		<< "in the west - " << (m_West == NULL ? "No room" : m_West->get_name()) << endl;

}


ostream& operator <<(ostream& out, Room& room) {

	room.print();
	return out;

 }

Room::Room(string name) :
	m_name(name),
	m_item(NULL),
	m_monster(NULL),
	m_North(NULL),
	m_South(NULL),
	m_East(NULL),
	m_West(NULL),
	num_of_item(0),
	num_of_monster(0)

{};

int Room:: room_count(){
    int sum = 0;
    if(this == nullptr)
        return 0;
    if(visited)
        return 0;
    visited = true;
    sum+= m_North->room_count()+m_East->room_count()+m_South->room_count()+m_West->room_count();
    visited = false;
    return sum+1;
}


Room::~Room() {
    delete[] m_item;
    delete[] m_monster;
delete_room();
}


