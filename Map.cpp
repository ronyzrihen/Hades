#include "Map.h"


Map::Map(Room& source)
	:
	name(NULL),
	rooms(new Room(source)),
	numberofrooms(1)
{}

Map::~Map() {
	delete[]rooms;
	
}

Map& Map::operator=(Map& source) {
	if (this == &source)
		return *this;

	name = source.name;
	numberofrooms = source.numberofrooms;

}



