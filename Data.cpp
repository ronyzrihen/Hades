#include "Data.h"


void Data:: add_map(Map& map) {

	Map* new_mapsdata = new Map[mapsize+1];

	for (int i = 0; i < mapsize; i++)
	{
		new_mapsdata[i] =mapsdata[i];
	}
	mapsize++;
	new_mapsdata[mapsize] = map;
	delete[] mapsdata;
	mapsdata = new_mapsdata;
}


void Data::add_room(Room& room) {

        Room *copy = new Room(room);
    if(roomsize == 0){
        *roomsData = new Room[roomsize+1];
        *roomsData = copy;
        roomsize++;
        return;
    }

	Room** new_room ;
    memcpy(new_room,roomsData,(roomsize+1)*sizeof(Room*));
    new_room[roomsize+1] = copy;
	roomsize++;
    for(int i =0 ; i < roomsize-1; i++){

        if(&roomsData[i]!= NULL)
            delete &roomsData[i];
    }

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
		if (mapsdata[i].get_name() == name)
			return &mapsdata[i];
	}
	return NULL;
}

void Data::print_rooms(){
    for (int i = 0 ; i < roomsize; i++){
        cout << roomsData[i] << endl;
    }
}

