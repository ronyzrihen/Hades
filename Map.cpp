
/*
Ofek Eliyahu 207753120
Rony Zrihen 318917549
*/


#include "Map.h"
using namespace std;

Map::Map()
    :
    name(" "),
    numberofrooms(0),
    rooms(NULL),
    curr_room(NULL)
{}


Map::Map(const Map& source)
	:
	name(source.name),
	numberofrooms(source.numberofrooms)

{
    if(source.rooms == NULL)
        rooms = NULL;
    else{rooms = new Room(*source.rooms);}
    curr_room = rooms;
}

Map::~Map() {
	delete rooms; //todo dont know
}


Map& Map::operator=(const Map& source) {
	if (this == &source)
		return *this;


	numberofrooms = source.numberofrooms;
    delete rooms;
    rooms = new Room(*source.rooms);
    curr_room = rooms;

    return *this;
}


void Map::add_room(Room& room, direction dir ){


    if (rooms == nullptr) {

        rooms = new Room(room);
        curr_room = rooms;
        numberofrooms = room_count();
        return;
    }

    if(rooms->find_room(room.get_name()) != nullptr ){
        cout << "Room already exist in this map\n";
        return;
    }

    if (!curr_room->check_room(room, dir)){
        cout << "Room was not added to map\n";
        return;
    }
    if (!curr_room->Add_Room(&room, dir)) {
        return;
    }

        curr_room = curr_room->move_room(dir);
        numberofrooms++;

}

Map& Map:: operator+=(Map& source){
  if (rooms == NULL){

      numberofrooms = room_count();
      rooms = new Room(*(source.rooms));
      curr_room = rooms;
      return *this;
  }
    Room* prev= NULL;
    curr_room = rooms;
    source.curr_room = source.rooms;
    while(source.curr_room->get_North() != NULL){
        source.curr_room = source.curr_room->move_room(north);
    }

    while(curr_room->get_South() != NULL){
        curr_room = curr_room->move_room(south);
    }

            curr_room->copy_South(*source.curr_room);
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






