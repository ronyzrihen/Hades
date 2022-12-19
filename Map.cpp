#include "Map.h"
using namespace std;

Map::Map(Map& source)
	:
	name(source.name),
	rooms(new Room(*source.rooms)),
    curr_room(rooms),
	numberofrooms(source.numberofrooms),
    room_names(new string[source.numberofrooms])
{
    for (int i = 0 ; i < numberofrooms ; i++){
        room_names[i] = source.room_names[i];
    }
}

Map::~Map() {
	rooms->delete_room(*rooms); //todo dont know
    delete[] room_names;
}

Map& Map::operator=(Map& source) {
	if (this == &source)
		return *this;

    *rooms = *(source.rooms);
    curr_room = source.curr_room;
	name = source.name;
	numberofrooms = source.numberofrooms;

    delete[]room_names;
    room_names = new string[numberofrooms];
    for(int i = 0 ; i < numberofrooms ;  i++){
        room_names[i] = source.room_names[i];
    }

    return *this;
}

void Map::add_room(Room& room, direction dir ){

    if(rooms->find_room(room.get_name()) != NULL ){
        cout << "Room already exist in this map\n";
        return;
    }

    if (rooms == NULL) {

        rooms = new Room(room);
        curr_room = rooms;
        numberofrooms++;
        return;
    }


    if (curr_room->check_room(room,dir) == false){
        cout << "Room was not added to map\n";
        return;
    }
        if(curr_room->Add_Room(&room, dir) == false){
            return;
        }

        curr_room = curr_room->move_room(dir);
        numberofrooms++;

        string* new_room_name = new string[numberofrooms];
        for(int i = 0; i < numberofrooms-1 ; i++){
            new_room_name[i] = room_names[i];
        }
        new_room_name[numberofrooms] = room.get_name();
        delete [] room_names;
        room_names = new_room_name;
}

Map& Map:: operator+=(Map& source){
    Room* prev= NULL;
    curr_room = rooms;
    source.curr_room = source.rooms;
    while(source.curr_room->get_North() != NULL){
        source.curr_room = source.curr_room->move_room(north);
    }

    while(curr_room->get_South() != NULL){
        curr_room = curr_room->move_room(south);
    }

            curr_room->set_South(*source.curr_room);
            prev = curr_room;
            curr_room = curr_room->get_South();
            curr_room->set_North(prev);

            return *this;
}

Map Map:: operator+(Map& map){

Map new_map = *this;
new_map+=map;
return new_map;

}






