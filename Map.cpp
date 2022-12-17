#include "Map.h"


Map::Map(Map& source)
	:
	name(source.name),
	rooms(new Room(*source.rooms)),
    curr_room(rooms),
	numberofrooms(source.numberofrooms)
{}

Map::~Map() {
	rooms->delete_room(*rooms); //todo dont know
}

Map& Map::operator=(Map& source) {
	if (this == &source)
		return *this;

    *rooms = *(source.rooms);
    curr_room = source.curr_room;
	name = source.name;
	numberofrooms = source.numberofrooms;


}

void Map::add_room(Room& room, direction dir ){

    if(rooms->find_room(room.get_name()) != NULL ){
        cout << "Room already exist in this map\n";
        return;
    }
    if (curr_room->checkroom(dir) == false){
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



