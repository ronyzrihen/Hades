#include "Data.h"


void Data:: add_map(const Map& map) {

	Map* copy = new Map(map);
	if (mapsize == 0) {
		mapsdata = new Map * [mapsize + 1];
		*mapsdata = copy;
		mapsize++;
		return;
	}

	Map** new_map=new Map*[mapsize+1];
	for (int i = 0; i < mapsize; i++) {
		new_map[i] = mapsdata[i];
	}
	
	new_map[mapsize] = copy;
	delete[] mapsdata;
	mapsize++;
	mapsdata = new_map;
}


void Data::add_room(Room& room) {

        Room *copy = new Room(room);
    if(roomsize == 0){
        roomsData = new Room*[roomsize+1];
        *roomsData = copy;
        roomsize++;
        return;
    }

	Room** new_room= new  Room * [roomsize + 1];
	// (memcpy(new_room, roomsData, (roomsize) * sizeof(Room*));
	for (int i = 0; i < roomsize; i++)
	{
		new_room[i] = roomsData[i];
	}

    new_room[roomsize] = copy;
	roomsize++;
	delete[]roomsData;

	roomsData = new_room;
	
}




Room* Data:: getroom(string name) {

	for (int i = 0; i < roomsize; i++)
	{
		if (roomsData[i]->get_name() == name)
		{
			return roomsData[i];
		}
	}

	return NULL;
}


Map* Data::getmap(string name) {

	for (int i = 0; i < mapsize; i++)
	{
		if (mapsdata[i]->get_name() == name)
			return mapsdata[i];
	}
	return NULL;
}

void Data::print_rooms(){
    for (int i = 0 ; i < roomsize; i++){
        cout << roomsData[i] << endl;
    }
}

void Data::print_map() {
	for (int i = 0; i < mapsize; i++) {
		cout << mapsdata[i]->get_name() << endl;
		mapsdata[i]->print_rooms();
		cout << "========================================================\n";
	}
}